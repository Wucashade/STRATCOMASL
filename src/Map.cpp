#include "../include/Map.hpp"
#include "../include/Window.hpp"
#include "../include/CustomSDLFunctions.hpp"
#include <utility>
#include <cmath>




int Map::mapTopLeftX;
int Map::mapTopLeftY;
double Map::zoomLevel;
int Map::uIHeight;

Map::~Map() {
}

void Map::init(){
    mapTopLeftX = mapTopLeftY = 0;
    zoomLevel = 1;
    uIHeight = 50;

    auto otypes = osmium::osm_entity_bits::node | osmium::osm_entity_bits::way;

    index_t index;
    cache_t cache{index};

    const char* inputFile = "../images/australia_oceania_latest.pbf";
    osmium::io::Reader reader{inputFile, otypes};
    osmium::apply(reader, cache, handler);

    std::cout << handler.getAdministrativeBoundaryNodes().size();

    reader.close();
    
}

void Map::update(){
}

void Map::render(){
    
    renderBackground();
}

void Map::renderBackground(){
    std::vector<std::pair<double, double>> nodes = handler.getAdministrativeBoundaryNodes();
    
    
    if (nodes.size() > 0){
        SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
        for (size_t i = 0; i < nodes.size() - 1; ++i) {

            
            int currentLong = static_cast<int>(convertLongitudeToX(nodes[i].second));
            int currentLat = static_cast<int>(convertLatitudeToY(nodes[i].first));
            int nextLong = static_cast<int>(convertLongitudeToX(nodes[i+1].second));
            int nextLat = static_cast<int>(convertLatitudeToY(nodes[i+1].first));

            
            SDL_RenderDrawLine(Window::renderer, currentLong, currentLat, nextLong, nextLat);
            
        }

    }
    
}

int Map::convertLongitudeToX(double longitude){
    double worldx = ORIGIN + longitude * PIXELS_PER_DEGREE;
    
    const int scale = pow(2, zoomLevel);
    double pixelCoordX = worldx * scale;

    return pixelCoordX;

}

int Map::convertLatitudeToY(double latitude){
    double sinY = std::sin(latitude * M_PI/180);
    sinY = std::min(std::max(sinY, -0.9999), 0.9999);
    double worldy = ORIGIN + 0.5 * (std::log((1 + sinY) / (1 - sinY)) * -PIXELS_PER_RADIAN);
    
    const int scale = pow(2, zoomLevel);
    double pixelCoordY = worldy * scale;
    return pixelCoordY;
}

void Map::handleMouseButtonDown(SDL_MouseButtonEvent& b){
    if(b.button == SDL_BUTTON_LEFT){
        int x, y;
        SDL_GetMouseState(&x, &y);
        setMouseClickPos(x,y);
        std::cout << "This pixel is frame: x-" << std::floor(getMouseClickPosX() / TILE_SIZE) << " y-" << std::floor(getMouseClickPosY() / TILE_SIZE) << std::endl;
    }
}

void Map::setMouseClickPos(int x, int y){
    lastMousePosX = x;
    lastMousePosY = y;
}

int Map::getMouseClickPosX(){
    return lastMousePosX;
}

int Map::getMouseClickPosY(){
    return lastMousePosY;
}

void Map::zoomIn(){
    if(zoomLevel < 11){
        zoomLevel += 1;
    }
}

void Map::zoomOut(){
    if(zoomLevel > 1){
        zoomLevel -= 1;
    }
}
