#ifndef OSMDATAHANDLER_H
#define OSMDATAHANDLER_H

#include <osmium/handler.hpp>
#include <osmium/osm/node.hpp>
#include <osmium/osm/way.hpp>
#include <osmium/visitor.hpp>
#include <osmium/io/any_input.hpp>
#include <osmium/osm.hpp>
#include <osmium/tags/filter.hpp>
#include <osmium/io/pbf_input.hpp>
#include <osmium/osm/relation.hpp>
#include <osmium/osm/types.hpp>
#include <osmium/osm/location.hpp>


#include <iostream>
#include <vector>

class OsmDataHandler : public osmium::handler::Handler{

    public:
        void way(const osmium::Way& way);
        void relation(const osmium::Relation& relation);
        std::vector<std::pair<double, double>> getAdministrativeBoundaryNodes() const;
        std::vector<osmium::Node> getNodesByIds(const osmium::io::File& file, const std::vector<osmium::object_id_type>& node_ids);



    private:
        std::vector<std::pair<double, double>> administrativeBoundryNodes;
};


#endif
