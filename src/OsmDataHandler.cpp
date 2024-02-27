#include "../include/OsmDataHandler.hpp"
#include "../include/Window.hpp"


void OsmDataHandler::way(const osmium::Way& way) {
    const osmium::TagList& tags= way.tags();
    const char* border = tags.get_value_by_key("boundary");
    const char* countryBorder = tags.get_value_by_key("admin_level");
    if((border && !std::strcmp(border, "administrative")) && (countryBorder && !std::strcmp(countryBorder, "2"))){ 
        for (const auto& node_ref : way.nodes()){
            
            if(node_ref.location()){
                administrativeBoundryNodes.emplace_back(std::make_pair(node_ref.location().lat(), node_ref.location().lon()));
            }

        }
    }

    
}


void OsmDataHandler::relation(const osmium::Relation& relation) {
}

std::vector<std::pair<double, double>> OsmDataHandler::getAdministrativeBoundaryNodes() const {
    return administrativeBoundryNodes;
}



    