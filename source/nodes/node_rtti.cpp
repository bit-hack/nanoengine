#include "node_null.h"
#include "node_script.h"
#include "node_sprite.h"
#include "node_tilemap.h"


// root scene graph object
gc_rtti_t sg_object_t::RTTI{ node_type_object };

// derived objects
gc_rtti_t node_null_t   ::RTTI{ sg_object_t::RTTI, node_type_null    };
gc_rtti_t node_script_t ::RTTI{ sg_object_t::RTTI, node_type_script  };
gc_rtti_t node_sprite_t ::RTTI{ sg_object_t::RTTI, node_type_sprite  };
gc_rtti_t node_tilemap_t::RTTI{ sg_object_t::RTTI, node_type_tilemap };
