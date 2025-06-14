#ifndef __MCPPV_TYPES__
#define __MCPPV_TYPES__

#include <mcpp/mcpp.h>

namespace mcppv {

enum ModelType { BLOCK, PLANE, FOLIAGE, WALL, SLAB };

ModelType getModelType(const mcpp::BlockType& blockType) {
    switch (blockType.id) {
    case mcpp::Blocks::POWERED_RAIL.id:
    case mcpp::Blocks::DETECTOR_RAIL.id:
    case mcpp::Blocks::RAIL.id:
    case mcpp::Blocks::STONE_PRESSURE_PLATE.id:
    case mcpp::Blocks::WOODEN_PRESSURE_PLATE.id:
    case mcpp::Blocks::SNOW.id:
    case mcpp::Blocks::ACTIVATOR_RAIL.id:
    case mcpp::Blocks::REDSTONE_REPEATER_BLOCK_OFF.id:
    case mcpp::Blocks::REDSTONE_REPEATER_BLOCK_ON.id:
    case mcpp::Blocks::WHITE_CARPET.id: // CARPETS
    case mcpp::Blocks::WEIGHTED_PRESSURE_PLATE_LIGHT.id:
    case mcpp::Blocks::WEIGHTED_PRESSURE_PLATE_HEAVY.id:
    case mcpp::Blocks::REDSTONE_COMPARATOR_INACTIVE.id:
    case mcpp::Blocks::REDSTONE_COMPARATOR_ACTIVE.id:
    case mcpp::Blocks::LILY_PAD.id:
    case mcpp::Blocks::END_PORTAL.id:
    case mcpp::Blocks::TRIPWIRE.id:
    case mcpp::Blocks::IRON_TRAPDOOR.id:
    case mcpp::Blocks::WOODEN_TRAPDOOR.id:
    case mcpp::Blocks::REDSTONE_WIRE.id:
        return PLANE;
    case mcpp::Blocks::OAK_SAPLING.id: // SAPLINGS
    case mcpp::Blocks::COBWEB.id:
    case mcpp::Blocks::DEAD_SHRUB.id: // SHRUBS kinda
    case mcpp::Blocks::DEAD_BUSH.id:
    case mcpp::Blocks::DANDELION.id:
    case mcpp::Blocks::POPPY.id: // FLOWERS
    case mcpp::Blocks::BROWN_MUSHROOM.id:
    case mcpp::Blocks::RED_MUSHROOM.id:
    case mcpp::Blocks::TORCH.id:
    case mcpp::Blocks::WHEAT_CROPS.id:
    case mcpp::Blocks::REDSTONE_TORCH_OFF.id:
    case mcpp::Blocks::REDSTONE_TORCH_ON.id:
    case mcpp::Blocks::COCOA.id:
    case mcpp::Blocks::BREWING_STAND.id:
    case mcpp::Blocks::BEETROOT_BLOCK.id:
    case mcpp::Blocks::CHORUS_PLANT.id:
    case mcpp::Blocks::CHORUS_FLOWER.id:
    case mcpp::Blocks::END_ROD.id:
    case mcpp::Blocks::SUNFLOWER.id: // TALL PLANTS
    case mcpp::Blocks::FREESTANDING_BANNER.id:
    case mcpp::Blocks::WALLMOUNTED_BANNER.id:
    case mcpp::Blocks::FLOWER_POT.id:
    case mcpp::Blocks::CARROTS.id:
    case mcpp::Blocks::POTATOES.id:
    case mcpp::Blocks::NETHER_WART.id:
    case mcpp::Blocks::SUGAR_CANES.id:
    case mcpp::Blocks::PUMPKIN_STEM.id:
    case mcpp::Blocks::MELON_STEM.id:
        return FOLIAGE;
    case mcpp::Blocks::GLASS_PANE.id:
    case mcpp::Blocks::WHITE_STAINED_GLASS_PANE.id: // STAINED_GLASS_PANES
    case mcpp::Blocks::IRON_BARS.id:
    case mcpp::Blocks::OAK_DOOR_BLOCK.id:
    case mcpp::Blocks::IRON_DOOR_BLOCK.id:
    case mcpp::Blocks::DARK_OAK_DOOR_BLOCK.id:
    case mcpp::Blocks::BIRCH_DOOR_BLOCK.id:
    case mcpp::Blocks::ACACIA_DOOR_BLOCK.id:
    case mcpp::Blocks::JUNGLE_DOOR_BLOCK.id:
    case mcpp::Blocks::SPRUCE_DOOR_BLOCK.id:
    case mcpp::Blocks::TRIPWIRE_HOOK.id:
    case mcpp::Blocks::LADDER.id:
    case mcpp::Blocks::VINES.id:
    case mcpp::Blocks::NETHER_PORTAL.id:
        return WALL;
    case mcpp::Blocks::DAYLIGHT_SENSOR.id:
    case mcpp::Blocks::INVERTED_DAYLIGHT_SENSOR.id:
    case mcpp::Blocks::PURPUR_DOUBLE_SLAB.id:
    case mcpp::Blocks::PURPUR_SLAB.id:
    case mcpp::Blocks::DOUBLE_STONE_SLAB.id:    // DOUBLE_SLABS
    case mcpp::Blocks::STONE_SLAB.id:           // SLABS
    case mcpp::Blocks::DOUBLE_OAK_WOOD_SLAB.id: // DOUBLE_WOOD_SLABS
    case mcpp::Blocks::OAK_WOOD_SLAB.id:        // WOOD_SLABS
    case mcpp::Blocks::DOUBLE_RED_SANDSTONE_SLAB.id:
    case mcpp::Blocks::RED_SANDSTONE_SLAB.id:
        return SLAB;
    default:
        return BLOCK;
    }
}

bool isTransparent(const mcpp::BlockType& blockType) {
    switch (blockType.id) {
    case mcpp::Blocks::GLASS.id:
    case mcpp::Blocks::GLASS_PANE.id:
    case mcpp::Blocks::WHITE_STAINED_GLASS_PANE.id: // STAINED_GLASS_PANES
    case mcpp::Blocks::WHITE_STAINED_GLASS.id:
    case mcpp::Blocks::STILL_WATER.id:
    case mcpp::Blocks::FLOWING_WATER.id:
    case mcpp::Blocks::ICE.id:
        return true;
    default:
        return false;
    }
}

std::string getBlockTexture(const mcpp::BlockType& blockType) {
    std::string textureName = "";

    if (blockType == mcpp::Blocks::STONE) {
        textureName += "stone";
    } else if (blockType == mcpp::Blocks::GRANITE) {
        textureName += "granite";
    } else if (blockType == mcpp::Blocks::POLISHED_GRANITE) {
        textureName += "polished_granite";
    } else if (blockType == mcpp::Blocks::DIORITE) {
        textureName += "diorite";
    } else if (blockType == mcpp::Blocks::POLISHED_DIORITE) {
        textureName += "polished_diorite";
    } else if (blockType == mcpp::Blocks::ANDESITE) {
        textureName += "andesite";
    } else if (blockType == mcpp::Blocks::POLISHED_ANDESITE) {
        textureName += "polished_andesite";
    } else if (blockType == mcpp::Blocks::GRASS) {
        textureName += "grass";
    } else if (blockType == mcpp::Blocks::DIRT) {
        textureName += "dirt";
    } else if (blockType == mcpp::Blocks::COARSE_DIRT) {
        textureName += "coarse_dirt";
    } else if (blockType == mcpp::Blocks::PODZOL) {
        textureName += "podzol";
    } else if (blockType == mcpp::Blocks::COBBLESTONE) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::OAK_WOOD_PLANK) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::SPRUCE_WOOD_PLANK) {
        textureName += "spruce_wood_plank";
    } else if (blockType == mcpp::Blocks::BIRCH_WOOD_PLANK) {
        textureName += "birch_wood_plank";
    } else if (blockType == mcpp::Blocks::JUNGLE_WOOD_PLANK) {
        textureName += "jungle_wood_plank";
    } else if (blockType == mcpp::Blocks::ACACIA_WOOD_PLANK) {
        textureName += "acacia_wood_plank";
    } else if (blockType == mcpp::Blocks::DARK_OAK_WOOD_PLANK) {
        textureName += "dark_oak_wood_plank";
    } else if (blockType == mcpp::Blocks::OAK_SAPLING) {
        textureName += "oak_sapling";
    } else if (blockType == mcpp::Blocks::SPRUCE_SAPLING) {
        textureName += "spruce_sapling";
    } else if (blockType == mcpp::Blocks::BIRCH_SAPLING) {
        textureName += "birch_sapling";
    } else if (blockType == mcpp::Blocks::JUNGLE_SAPLING) {
        textureName += "jungle_sapling";
    } else if (blockType == mcpp::Blocks::ACACIA_SAPLING) {
        textureName += "acacia_sapling";
    } else if (blockType == mcpp::Blocks::DARK_OAK_SAPLING) {
        textureName += "dark_oak_sapling";
    } else if (blockType == mcpp::Blocks::BEDROCK) {
        textureName += "bedrock";
    } else if (blockType == mcpp::Blocks::FLOWING_WATER) {
        textureName += "water";
    } else if (blockType == mcpp::Blocks::STILL_WATER) {
        textureName += "water";
    } else if (blockType == mcpp::Blocks::FLOWING_LAVA) {
        textureName += "lava";
    } else if (blockType == mcpp::Blocks::STILL_LAVA) {
        textureName += "lava";
    } else if (blockType == mcpp::Blocks::SAND) {
        textureName += "sand";
    } else if (blockType == mcpp::Blocks::RED_SAND) {
        textureName += "red_sand";
    } else if (blockType == mcpp::Blocks::GRAVEL) {
        textureName += "gravel";
    } else if (blockType == mcpp::Blocks::GOLD_ORE) {
        textureName += "gold_ore";
    } else if (blockType == mcpp::Blocks::IRON_ORE) {
        textureName += "iron_ore";
    } else if (blockType == mcpp::Blocks::COAL_ORE) {
        textureName += "coal_ore";
    } else if (blockType == mcpp::Blocks::OAK_WOOD) {
        textureName += "oak_wood";
    } else if (blockType == mcpp::Blocks::SPRUCE_WOOD) {
        textureName += "spruce_wood";
    } else if (blockType == mcpp::Blocks::BIRCH_WOOD) {
        textureName += "birch_wood";
    } else if (blockType == mcpp::Blocks::JUNGLE_WOOD) {
        textureName += "jungle_wood";
    } else if (blockType == mcpp::Blocks::OAK_LEAVES) {
        textureName += "oak_leaves";
    } else if (blockType == mcpp::Blocks::SPRUCE_LEAVES) {
        textureName += "spruce_leaves";
    } else if (blockType == mcpp::Blocks::BIRCH_LEAVES) {
        textureName += "birch_leaves";
    } else if (blockType == mcpp::Blocks::JUNGLE_LEAVES) {
        textureName += "jungle_leaves";
    } else if (blockType == mcpp::Blocks::SPONGE) {
        textureName += "sponge";
    } else if (blockType == mcpp::Blocks::WET_SPONGE) {
        textureName += "wet_sponge";
    } else if (blockType == mcpp::Blocks::GLASS) {
        textureName += "glass";
    } else if (blockType == mcpp::Blocks::LAPIS_LAZULI_ORE) {
        textureName += "lapis_lazuli_ore";
    } else if (blockType == mcpp::Blocks::LAPIS_LAZULI_BLOCK) {
        textureName += "lapis_lazuli_block";
    } else if (blockType == mcpp::Blocks::DISPENSER) {
        textureName += "dispenser";
    } else if (blockType == mcpp::Blocks::SANDSTONE) {
        textureName += "sandstone";
    } else if (blockType == mcpp::Blocks::CHISELED_SANDSTONE) {
        textureName += "chiseled_sandstone";
    } else if (blockType == mcpp::Blocks::SMOOTH_SANDSTONE) {
        textureName += "smooth_sandstone";
    } else if (blockType == mcpp::Blocks::NOTE_BLOCK) {
        textureName += "note_block";
    } else if (blockType == mcpp::Blocks::BED) {
        textureName += "bed";
    } else if (blockType == mcpp::Blocks::POWERED_RAIL) {
        textureName += "powered_rail";
    } else if (blockType == mcpp::Blocks::DETECTOR_RAIL) {
        textureName += "detector_rail";
    } else if (blockType == mcpp::Blocks::STICKY_PISTON) {
        textureName += "sticky_piston";
    } else if (blockType == mcpp::Blocks::COBWEB) {
        textureName += "cobweb";
    } else if (blockType == mcpp::Blocks::DEAD_SHRUB) {
        textureName += "dead_shrub";
    } else if (blockType == mcpp::Blocks::TALL_GRASS) {
        textureName += "tall_grass";
    } else if (blockType == mcpp::Blocks::FERN) {
        textureName += "fern";
    } else if (blockType == mcpp::Blocks::DEAD_BUSH) {
        textureName += "dead_bush";
    } else if (blockType == mcpp::Blocks::PISTON) {
        textureName += "piston";
    } else if (blockType == mcpp::Blocks::PISTON_HEAD) {
        textureName += "piston_head";
    } else if (blockType == mcpp::Blocks::WHITE_WOOL) {
        textureName += "white_wool";
    } else if (blockType == mcpp::Blocks::ORANGE_WOOL) {
        textureName += "orange_wool";
    } else if (blockType == mcpp::Blocks::MAGENTA_WOOL) {
        textureName += "magenta_wool";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_WOOL) {
        textureName += "light_blue_wool";
    } else if (blockType == mcpp::Blocks::YELLOW_WOOL) {
        textureName += "yellow_wool";
    } else if (blockType == mcpp::Blocks::LIME_WOOL) {
        textureName += "lime_wool";
    } else if (blockType == mcpp::Blocks::PINK_WOOL) {
        textureName += "pink_wool";
    } else if (blockType == mcpp::Blocks::GRAY_WOOL) {
        textureName += "gray_wool";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_WOOL) {
        textureName += "light_gray_wool";
    } else if (blockType == mcpp::Blocks::CYAN_WOOL) {
        textureName += "cyan_wool";
    } else if (blockType == mcpp::Blocks::PURPLE_WOOL) {
        textureName += "purple_wool";
    } else if (blockType == mcpp::Blocks::BLUE_WOOL) {
        textureName += "blue_wool";
    } else if (blockType == mcpp::Blocks::BROWN_WOOL) {
        textureName += "brown_wool";
    } else if (blockType == mcpp::Blocks::GREEN_WOOL) {
        textureName += "green_wool";
    } else if (blockType == mcpp::Blocks::RED_WOOL) {
        textureName += "red_wool";
    } else if (blockType == mcpp::Blocks::BLACK_WOOL) {
        textureName += "black_wool";
    } else if (blockType == mcpp::Blocks::DANDELION) {
        textureName += "dandelion";
    } else if (blockType == mcpp::Blocks::POPPY) {
        textureName += "poppy";
    } else if (blockType == mcpp::Blocks::BLUE_ORCHID) {
        textureName += "blue_orchid";
    } else if (blockType == mcpp::Blocks::ALLIUM) {
        textureName += "allium";
    } else if (blockType == mcpp::Blocks::AZURE_BLUET) {
        textureName += "azure_bluet";
    } else if (blockType == mcpp::Blocks::RED_TULIP) {
        textureName += "red_tulip";
    } else if (blockType == mcpp::Blocks::ORANGE_TULIP) {
        textureName += "orange_tulip";
    } else if (blockType == mcpp::Blocks::WHITE_TULIP) {
        textureName += "white_tulip";
    } else if (blockType == mcpp::Blocks::PINK_TULIP) {
        textureName += "pink_tulip";
    } else if (blockType == mcpp::Blocks::OXEYE_DAISY) {
        textureName += "oxeye_daisy";
    } else if (blockType == mcpp::Blocks::BROWN_MUSHROOM) {
        textureName += "brown_mushroom";
    } else if (blockType == mcpp::Blocks::RED_MUSHROOM) {
        textureName += "red_mushroom";
    } else if (blockType == mcpp::Blocks::GOLD_BLOCK) {
        textureName += "gold_block";
    } else if (blockType == mcpp::Blocks::IRON_BLOCK) {
        textureName += "iron_block";
    } else if (blockType == mcpp::Blocks::DOUBLE_STONE_SLAB) {
        textureName += "stone";
    } else if (blockType == mcpp::Blocks::DOUBLE_SANDSTONE_SLAB) {
        textureName += "sandstone";
    } else if (blockType == mcpp::Blocks::DOUBLE_WOODEN_SLAB) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::DOUBLE_COBBLESTONE_SLAB) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::DOUBLE_BRICK_SLAB) {
        textureName += "bricks";
    } else if (blockType == mcpp::Blocks::DOUBLE_STONE_BRICK_SLAB) {
        textureName += "stone_bricks";
    } else if (blockType == mcpp::Blocks::DOUBLE_NETHER_BRICK_SLAB) {
        textureName += "nether_brick";
    } else if (blockType == mcpp::Blocks::DOUBLE_QUARTZ_SLAB) {
        textureName += "quartz_block";
    } else if (blockType == mcpp::Blocks::STONE_SLAB) {
        textureName += "stone_slab";
    } else if (blockType == mcpp::Blocks::SANDSTONE_SLAB) {
        textureName += "sandstone";
    } else if (blockType == mcpp::Blocks::WOODEN_SLAB) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::COBBLESTONE_SLAB) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::BRICK_SLAB) {
        textureName += "bricks";
    } else if (blockType == mcpp::Blocks::STONE_BRICK_SLAB) {
        textureName += "stone_bricks";
    } else if (blockType == mcpp::Blocks::NETHER_BRICK_SLAB) {
        textureName += "nether_brick";
    } else if (blockType == mcpp::Blocks::QUARTZ_SLAB) {
        textureName += "quartz_block";
    } else if (blockType == mcpp::Blocks::BRICKS) {
        textureName += "bricks";
    } else if (blockType == mcpp::Blocks::TNT) {
        textureName += "tnt";
    } else if (blockType == mcpp::Blocks::BOOKSHELF) {
        textureName += "bookshelf";
    } else if (blockType == mcpp::Blocks::MOSS_STONE) {
        textureName += "moss_stone";
    } else if (blockType == mcpp::Blocks::OBSIDIAN) {
        textureName += "obsidian";
    } else if (blockType == mcpp::Blocks::TORCH) {
        textureName += "torch";
    } else if (blockType == mcpp::Blocks::FIRE) {
        textureName += "fire";
    } else if (blockType == mcpp::Blocks::MONSTER_SPAWNER) {
        textureName += "monster_spawner";
    } else if (blockType == mcpp::Blocks::OAK_WOOD_STAIRS) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::CHEST) {
        textureName += "chest";
    } else if (blockType == mcpp::Blocks::REDSTONE_WIRE) {
        textureName += "redstone_wire";
    } else if (blockType == mcpp::Blocks::DIAMOND_ORE) {
        textureName += "diamond_ore";
    } else if (blockType == mcpp::Blocks::DIAMOND_BLOCK) {
        textureName += "diamond_block";
    } else if (blockType == mcpp::Blocks::CRAFTING_TABLE) {
        textureName += "crafting_table";
    } else if (blockType == mcpp::Blocks::WHEAT_CROPS) {
        textureName += "wheat_crops";
    } else if (blockType == mcpp::Blocks::FARMLAND) {
        textureName += "farmland";
    } else if (blockType == mcpp::Blocks::FURNACE) {
        textureName += "furnace";
    } else if (blockType == mcpp::Blocks::BURNING_FURNACE) {
        textureName += "burning_furnace";
    } else if (blockType == mcpp::Blocks::STANDING_SIGN_BLOCK) {
        textureName += "sign";
    } else if (blockType == mcpp::Blocks::OAK_DOOR_BLOCK) {
        textureName += "door_wood_upper";
    } else if (blockType == mcpp::Blocks::LADDER) {
        textureName += "ladder";
    } else if (blockType == mcpp::Blocks::RAIL) {
        textureName += "rail";
    } else if (blockType == mcpp::Blocks::COBBLESTONE_STAIRS) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::WALLMOUNTED_SIGN_BLOCK) {
        textureName += "sign";
    } else if (blockType == mcpp::Blocks::LEVER) {
        textureName += "lever";
    } else if (blockType == mcpp::Blocks::STONE_PRESSURE_PLATE) {
        textureName += "stone";
    } else if (blockType == mcpp::Blocks::IRON_DOOR_BLOCK) {
        textureName += "door_iron_upper";
    } else if (blockType == mcpp::Blocks::WOODEN_PRESSURE_PLATE) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::REDSTONE_ORE) {
        textureName += "redstone_ore";
    } else if (blockType == mcpp::Blocks::GLOWING_REDSTONE_ORE) {
        textureName += "redstone_ore";
    } else if (blockType == mcpp::Blocks::REDSTONE_TORCH_OFF) {
        textureName += "redstone_torch_off";
    } else if (blockType == mcpp::Blocks::REDSTONE_TORCH_ON) {
        textureName += "redstone_torch_on";
    } else if (blockType == mcpp::Blocks::STONE_BUTTON) {
        textureName += "stone";
    } else if (blockType == mcpp::Blocks::SNOW) {
        textureName += "snow_block";
    } else if (blockType == mcpp::Blocks::ICE) {
        textureName += "ice";
    } else if (blockType == mcpp::Blocks::SNOW_BLOCK) {
        textureName += "snow_block";
    } else if (blockType == mcpp::Blocks::CACTUS) {
        textureName += "cactus";
    } else if (blockType == mcpp::Blocks::CLAY) {
        textureName += "clay";
    } else if (blockType == mcpp::Blocks::SUGAR_CANES) {
        textureName += "sugar_canes";
    } else if (blockType == mcpp::Blocks::JUKEBOX) {
        textureName += "jukebox";
    } else if (blockType == mcpp::Blocks::OAK_FENCE) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::PUMPKIN) {
        textureName += "pumpkin";
    } else if (blockType == mcpp::Blocks::NETHERRACK) {
        textureName += "netherrack";
    } else if (blockType == mcpp::Blocks::SOUL_SAND) {
        textureName += "soul_sand";
    } else if (blockType == mcpp::Blocks::GLOWSTONE) {
        textureName += "glowstone";
    } else if (blockType == mcpp::Blocks::NETHER_PORTAL) {
        textureName += "nether_portal";
    } else if (blockType == mcpp::Blocks::JACK_OLANTERN) {
        textureName += "jack_olantern";
    } else if (blockType == mcpp::Blocks::CAKE_BLOCK) {
        textureName += "cake_block";
    } else if (blockType == mcpp::Blocks::REDSTONE_REPEATER_BLOCK_OFF) {
        textureName += "redstone_repeater_block_off";
    } else if (blockType == mcpp::Blocks::REDSTONE_REPEATER_BLOCK_ON) {
        textureName += "redstone_repeater_block_on";
    } else if (blockType == mcpp::Blocks::WHITE_STAINED_GLASS) {
        textureName += "glass_white";
    } else if (blockType == mcpp::Blocks::ORANGE_STAINED_GLASS) {
        textureName += "glass_orange";
    } else if (blockType == mcpp::Blocks::MAGENTA_STAINED_GLASS) {
        textureName += "glass_magenta";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_STAINED_GLASS) {
        textureName += "glass_light_blue";
    } else if (blockType == mcpp::Blocks::YELLOW_STAINED_GLASS) {
        textureName += "glass_yellow";
    } else if (blockType == mcpp::Blocks::LIME_STAINED_GLASS) {
        textureName += "glass_lime";
    } else if (blockType == mcpp::Blocks::PINK_STAINED_GLASS) {
        textureName += "glass_pink";
    } else if (blockType == mcpp::Blocks::GRAY_STAINED_GLASS) {
        textureName += "glass_gray";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_STAINED_GLASS) {
        textureName += "glass_light_gray";
    } else if (blockType == mcpp::Blocks::CYAN_STAINED_GLASS) {
        textureName += "glass_cyan";
    } else if (blockType == mcpp::Blocks::PURPLE_STAINED_GLASS) {
        textureName += "glass_purple";
    } else if (blockType == mcpp::Blocks::BLUE_STAINED_GLASS) {
        textureName += "glass_blue";
    } else if (blockType == mcpp::Blocks::BROWN_STAINED_GLASS) {
        textureName += "glass_brown";
    } else if (blockType == mcpp::Blocks::GREEN_STAINED_GLASS) {
        textureName += "glass_green";
    } else if (blockType == mcpp::Blocks::RED_STAINED_GLASS) {
        textureName += "glass_red";
    } else if (blockType == mcpp::Blocks::BLACK_STAINED_GLASS) {
        textureName += "glass_black";
    } else if (blockType == mcpp::Blocks::WOODEN_TRAPDOOR) {
        textureName += "wooden_trapdoor";
    } else if (blockType == mcpp::Blocks::STONE_MONSTER_EGG) {
        textureName += "stone";
    } else if (blockType == mcpp::Blocks::COBBLESTONE_MONSTER_EGG) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::STONE_BRICK_MONSTER_EGG) {
        textureName += "stone_bricks";
    } else if (blockType == mcpp::Blocks::MOSSY_STONE_BRICK_MONSTER_EGG) {
        textureName += "mossy_stone_bricks";
    } else if (blockType == mcpp::Blocks::CRACKED_STONE_BRICK_MONSTER_EGG) {
        textureName += "cracked_stone_bricks";
    } else if (blockType == mcpp::Blocks::CHISELED_STONE_BRICK_MONSTER_EGG) {
        textureName += "chiseled_stone_bricks";
    } else if (blockType == mcpp::Blocks::STONE_BRICKS) {
        textureName += "stone_bricks";
    } else if (blockType == mcpp::Blocks::MOSSY_STONE_BRICKS) {
        textureName += "mossy_stone_bricks";
    } else if (blockType == mcpp::Blocks::CRACKED_STONE_BRICKS) {
        textureName += "cracked_stone_bricks";
    } else if (blockType == mcpp::Blocks::CHISELED_STONE_BRICKS) {
        textureName += "chiseled_stone_bricks";
    } else if (blockType == mcpp::Blocks::BROWN_MUSHROOM_BLOCK) {
        textureName += "brown_mushroom_block";
    } else if (blockType == mcpp::Blocks::RED_MUSHROOM_BLOCK) {
        textureName += "red_mushroom_block";
    } else if (blockType == mcpp::Blocks::IRON_BARS) {
        textureName += "iron_bars";
    } else if (blockType == mcpp::Blocks::GLASS_PANE) {
        textureName += "glass";
    } else if (blockType == mcpp::Blocks::MELON_BLOCK) {
        textureName += "melon_block";
    } else if (blockType == mcpp::Blocks::PUMPKIN_STEM) {
        textureName += "pumpkin_stem";
    } else if (blockType == mcpp::Blocks::MELON_STEM) {
        textureName += "melon_stem";
    } else if (blockType == mcpp::Blocks::VINES) {
        textureName += "vines";
    } else if (blockType == mcpp::Blocks::OAK_FENCE_GATE) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::BRICK_STAIRS) {
        textureName += "bricks";
    } else if (blockType == mcpp::Blocks::STONE_BRICK_STAIRS) {
        textureName += "stone_bricks";
    } else if (blockType == mcpp::Blocks::MYCELIUM) {
        textureName += "mycelium";
    } else if (blockType == mcpp::Blocks::LILY_PAD) {
        textureName += "lily_pad";
    } else if (blockType == mcpp::Blocks::NETHER_BRICK) {
        textureName += "nether_brick";
    } else if (blockType == mcpp::Blocks::NETHER_BRICK_FENCE) {
        textureName += "nether_brick";
    } else if (blockType == mcpp::Blocks::NETHER_BRICK_STAIRS) {
        textureName += "nether_brick";
    } else if (blockType == mcpp::Blocks::NETHER_WART) {
        textureName += "nether_wart";
    } else if (blockType == mcpp::Blocks::ENCHANTMENT_TABLE) {
        textureName += "enchantment_table";
    } else if (blockType == mcpp::Blocks::BREWING_STAND) {
        textureName += "brewing_stand";
    } else if (blockType == mcpp::Blocks::CAULDRON) {
        textureName += "cauldron";
    } else if (blockType == mcpp::Blocks::END_PORTAL) {
        textureName += "end_portal";
    } else if (blockType == mcpp::Blocks::END_PORTAL_FRAME) {
        textureName += "end_portal_frame";
    } else if (blockType == mcpp::Blocks::END_STONE) {
        textureName += "end_stone";
    } else if (blockType == mcpp::Blocks::DRAGON_EGG) {
        textureName += "dragon_egg";
    } else if (blockType == mcpp::Blocks::REDSTONE_LAMP_INACTIVE) {
        textureName += "redstone_lamp_inactive";
    } else if (blockType == mcpp::Blocks::REDSTONE_LAMP_ACTIVE) {
        textureName += "redstone_lamp_active";
    } else if (blockType == mcpp::Blocks::DOUBLE_OAK_WOOD_SLAB) {
        textureName += "oak_wood";
    } else if (blockType == mcpp::Blocks::DOUBLE_SPRUCE_WOOD_SLAB) {
        textureName += "spruce_wood";
    } else if (blockType == mcpp::Blocks::DOUBLE_BIRCH_WOOD_SLAB) {
        textureName += "birch_wood";
    } else if (blockType == mcpp::Blocks::DOUBLE_JUNGLE_WOOD_SLAB) {
        textureName += "jungle_wood";
    } else if (blockType == mcpp::Blocks::DOUBLE_ACACIA_WOOD_SLAB) {
        textureName += "acacia_wood";
    } else if (blockType == mcpp::Blocks::DOUBLE_DARK_OAK_WOOD_SLAB) {
        textureName += "dark_oak_wood";
    } else if (blockType == mcpp::Blocks::OAK_WOOD_SLAB) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::SPRUCE_WOOD_SLAB) {
        textureName += "spruce_wood_plank";
    } else if (blockType == mcpp::Blocks::BIRCH_WOOD_SLAB) {
        textureName += "birch_wood_plank";
    } else if (blockType == mcpp::Blocks::JUNGLE_WOOD_SLAB) {
        textureName += "jungle_wood_plank";
    } else if (blockType == mcpp::Blocks::ACACIA_WOOD_SLAB) {
        textureName += "acacia_wood_plank";
    } else if (blockType == mcpp::Blocks::DARK_OAK_WOOD_SLAB) {
        textureName += "dark_oak_wood_plank";
    } else if (blockType == mcpp::Blocks::COCOA) {
        textureName += "cocoa";
    } else if (blockType == mcpp::Blocks::SANDSTONE_STAIRS) {
        textureName += "sandstone";
    } else if (blockType == mcpp::Blocks::EMERALD_ORE) {
        textureName += "emerald_ore";
    } else if (blockType == mcpp::Blocks::ENDER_CHEST) {
        textureName += "ender_chest";
    } else if (blockType == mcpp::Blocks::TRIPWIRE_HOOK) {
        textureName += "tripwire_hook";
    } else if (blockType == mcpp::Blocks::TRIPWIRE) {
        textureName += "tripwire";
    } else if (blockType == mcpp::Blocks::EMERALD_BLOCK) {
        textureName += "emerald_block";
    } else if (blockType == mcpp::Blocks::SPRUCE_WOOD_STAIRS) {
        textureName += "spruce_wood_plank";
    } else if (blockType == mcpp::Blocks::BIRCH_WOOD_STAIRS) {
        textureName += "birch_wood_plank";
    } else if (blockType == mcpp::Blocks::JUNGLE_WOOD_STAIRS) {
        textureName += "jungle_wood_plank";
    } else if (blockType == mcpp::Blocks::COMMAND_BLOCK) {
        textureName += "command_block";
    } else if (blockType == mcpp::Blocks::BEACON) {
        textureName += "beacon";
    } else if (blockType == mcpp::Blocks::COBBLESTONE_WALL) {
        textureName += "cobblestone";
    } else if (blockType == mcpp::Blocks::MOSSY_COBBLESTONE_WALL) {
        textureName += "mossy_cobblestone";
    } else if (blockType == mcpp::Blocks::FLOWER_POT) {
        textureName += "flower_pot";
    } else if (blockType == mcpp::Blocks::CARROTS) {
        textureName += "carrots";
    } else if (blockType == mcpp::Blocks::POTATOES) {
        textureName += "potatoes";
    } else if (blockType == mcpp::Blocks::WOODEN_BUTTON) {
        textureName += "oak_wood_plank";
    } else if (blockType == mcpp::Blocks::MOB_HEAD) {
        textureName += "mob_head";
    } else if (blockType == mcpp::Blocks::ANVIL) {
        textureName += "anvil";
    } else if (blockType == mcpp::Blocks::TRAPPED_CHEST) {
        textureName += "trapped_chest";
    } else if (blockType == mcpp::Blocks::WEIGHTED_PRESSURE_PLATE_LIGHT) {
        textureName += "iron_block";
    } else if (blockType == mcpp::Blocks::WEIGHTED_PRESSURE_PLATE_HEAVY) {
        textureName += "gold_block";
    } else if (blockType == mcpp::Blocks::REDSTONE_COMPARATOR_INACTIVE) {
        textureName += "redstone_comparator_inactive";
    } else if (blockType == mcpp::Blocks::REDSTONE_COMPARATOR_ACTIVE) {
        textureName += "redstone_comparator_active";
    } else if (blockType == mcpp::Blocks::DAYLIGHT_SENSOR) {
        textureName += "daylight_sensor";
    } else if (blockType == mcpp::Blocks::REDSTONE_BLOCK) {
        textureName += "redstone_block";
    } else if (blockType == mcpp::Blocks::NETHER_QUARTZ_ORE) {
        textureName += "nether_quartz_ore";
    } else if (blockType == mcpp::Blocks::HOPPER) {
        textureName += "hopper";
    } else if (blockType == mcpp::Blocks::QUARTZ_BLOCK) {
        textureName += "quartz_block";
    } else if (blockType == mcpp::Blocks::CHISELED_QUARTZ_BLOCK) {
        textureName += "chiseled_quartz_block";
    } else if (blockType == mcpp::Blocks::PILLAR_QUARTZ_BLOCK) {
        textureName += "pillar_quartz_block";
    } else if (blockType == mcpp::Blocks::QUARTZ_STAIRS) {
        textureName += "quartz_block";
    } else if (blockType == mcpp::Blocks::ACTIVATOR_RAIL) {
        textureName += "activator_rail";
    } else if (blockType == mcpp::Blocks::DROPPER) {
        textureName += "dropper";
    } else if (blockType == mcpp::Blocks::WHITE_HARDENED_CLAY) {
        textureName += "white_hardened_clay";
    } else if (blockType == mcpp::Blocks::ORANGE_HARDENED_CLAY) {
        textureName += "orange_hardened_clay";
    } else if (blockType == mcpp::Blocks::MAGENTA_HARDENED_CLAY) {
        textureName += "magenta_hardened_clay";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_HARDENED_CLAY) {
        textureName += "light_blue_hardened_clay";
    } else if (blockType == mcpp::Blocks::YELLOW_HARDENED_CLAY) {
        textureName += "yellow_hardened_clay";
    } else if (blockType == mcpp::Blocks::LIME_HARDENED_CLAY) {
        textureName += "lime_hardened_clay";
    } else if (blockType == mcpp::Blocks::PINK_HARDENED_CLAY) {
        textureName += "pink_hardened_clay";
    } else if (blockType == mcpp::Blocks::GRAY_HARDENED_CLAY) {
        textureName += "gray_hardened_clay";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_HARDENED_CLAY) {
        textureName += "light_gray_hardened_clay";
    } else if (blockType == mcpp::Blocks::CYAN_HARDENED_CLAY) {
        textureName += "cyan_hardened_clay";
    } else if (blockType == mcpp::Blocks::PURPLE_HARDENED_CLAY) {
        textureName += "purple_hardened_clay";
    } else if (blockType == mcpp::Blocks::BLUE_HARDENED_CLAY) {
        textureName += "blue_hardened_clay";
    } else if (blockType == mcpp::Blocks::BROWN_HARDENED_CLAY) {
        textureName += "brown_hardened_clay";
    } else if (blockType == mcpp::Blocks::GREEN_HARDENED_CLAY) {
        textureName += "green_hardened_clay";
    } else if (blockType == mcpp::Blocks::RED_HARDENED_CLAY) {
        textureName += "red_hardened_clay";
    } else if (blockType == mcpp::Blocks::BLACK_HARDENED_CLAY) {
        textureName += "black_hardened_clay";
    } else if (blockType == mcpp::Blocks::WHITE_STAINED_GLASS_PANE) {
        textureName += "glass_white";
    } else if (blockType == mcpp::Blocks::ORANGE_STAINED_GLASS_PANE) {
        textureName += "glass_orange";
    } else if (blockType == mcpp::Blocks::MAGENTA_STAINED_GLASS_PANE) {
        textureName += "glass_magenta";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_STAINED_GLASS_PANE) {
        textureName += "glass_light_blue";
    } else if (blockType == mcpp::Blocks::YELLOW_STAINED_GLASS_PANE) {
        textureName += "glass_yellow";
    } else if (blockType == mcpp::Blocks::LIME_STAINED_GLASS_PANE) {
        textureName += "glass_lime";
    } else if (blockType == mcpp::Blocks::PINK_STAINED_GLASS_PANE) {
        textureName += "glass_pink";
    } else if (blockType == mcpp::Blocks::GRAY_STAINED_GLASS_PANE) {
        textureName += "glass_gray";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_STAINED_GLASS_PANE) {
        textureName += "glass_light_gray";
    } else if (blockType == mcpp::Blocks::CYAN_STAINED_GLASS_PANE) {
        textureName += "glass_cyan";
    } else if (blockType == mcpp::Blocks::PURPLE_STAINED_GLASS_PANE) {
        textureName += "glass_purple";
    } else if (blockType == mcpp::Blocks::BLUE_STAINED_GLASS_PANE) {
        textureName += "glass_blue";
    } else if (blockType == mcpp::Blocks::BROWN_STAINED_GLASS_PANE) {
        textureName += "glass_brown";
    } else if (blockType == mcpp::Blocks::GREEN_STAINED_GLASS_PANE) {
        textureName += "glass_green";
    } else if (blockType == mcpp::Blocks::RED_STAINED_GLASS_PANE) {
        textureName += "glass_red";
    } else if (blockType == mcpp::Blocks::BLACK_STAINED_GLASS_PANE) {
        textureName += "glass_black";
    } else if (blockType == mcpp::Blocks::ACACIA_LEAVES) {
        textureName += "acacia_leaves";
    } else if (blockType == mcpp::Blocks::DARK_OAK_LEAVES) {
        textureName += "dark_oak_leaves";
    } else if (blockType == mcpp::Blocks::ACACIA_WOOD) {
        textureName += "acacia_wood";
    } else if (blockType == mcpp::Blocks::DARK_OAK_WOOD) {
        textureName += "dark_oak_wood";
    } else if (blockType == mcpp::Blocks::ACACIA_WOOD_STAIRS) {
        textureName += "acacia_wood_plank";
    } else if (blockType == mcpp::Blocks::DARK_OAK_WOOD_STAIRS) {
        textureName += "dark_oak_wood_plank";
    } else if (blockType == mcpp::Blocks::SLIME_BLOCK) {
        textureName += "slime_block";
    } else if (blockType == mcpp::Blocks::BARRIER) {
        textureName += "barrier";
    } else if (blockType == mcpp::Blocks::IRON_TRAPDOOR) {
        textureName += "iron_trapdoor";
    } else if (blockType == mcpp::Blocks::PRISMARINE) {
        textureName += "prismarine";
    } else if (blockType == mcpp::Blocks::PRISMARINE_BRICKS) {
        textureName += "prismarine_bricks";
    } else if (blockType == mcpp::Blocks::DARK_PRISMARINE) {
        textureName += "dark_prismarine";
    } else if (blockType == mcpp::Blocks::SEA_LANTERN) {
        textureName += "sea_lantern";
    } else if (blockType == mcpp::Blocks::HAY_BALE) {
        textureName += "hay_bale";
    } else if (blockType == mcpp::Blocks::WHITE_CARPET) {
        textureName += "white_wool";
    } else if (blockType == mcpp::Blocks::ORANGE_CARPET) {
        textureName += "orange_wool";
    } else if (blockType == mcpp::Blocks::MAGENTA_CARPET) {
        textureName += "magenta_wool";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_CARPET) {
        textureName += "light_blue_wool";
    } else if (blockType == mcpp::Blocks::YELLOW_CARPET) {
        textureName += "yellow_wool";
    } else if (blockType == mcpp::Blocks::LIME_CARPET) {
        textureName += "lime_wool";
    } else if (blockType == mcpp::Blocks::PINK_CARPET) {
        textureName += "pink_wool";
    } else if (blockType == mcpp::Blocks::GRAY_CARPET) {
        textureName += "gray_wool";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_CARPET) {
        textureName += "light_gray_wool";
    } else if (blockType == mcpp::Blocks::CYAN_CARPET) {
        textureName += "cyan_wool";
    } else if (blockType == mcpp::Blocks::PURPLE_CARPET) {
        textureName += "purple_wool";
    } else if (blockType == mcpp::Blocks::BLUE_CARPET) {
        textureName += "blue_wool";
    } else if (blockType == mcpp::Blocks::BROWN_CARPET) {
        textureName += "brown_wool";
    } else if (blockType == mcpp::Blocks::GREEN_CARPET) {
        textureName += "green_wool";
    } else if (blockType == mcpp::Blocks::RED_CARPET) {
        textureName += "red_wool";
    } else if (blockType == mcpp::Blocks::BLACK_CARPET) {
        textureName += "black_wool";
    } else if (blockType == mcpp::Blocks::HARDENED_CLAY) {
        textureName += "hardened_clay";
    } else if (blockType == mcpp::Blocks::BLOCK_OF_COAL) {
        textureName += "block_of_coal";
    } else if (blockType == mcpp::Blocks::PACKED_ICE) {
        textureName += "packed_ice";
    } else if (blockType == mcpp::Blocks::SUNFLOWER) {
        textureName += "sunflower";
    } else if (blockType == mcpp::Blocks::LILAC) {
        textureName += "lilac";
    } else if (blockType == mcpp::Blocks::DOUBLE_TALLGRASS) {
        textureName += "tallgrass";
    } else if (blockType == mcpp::Blocks::LARGE_FERN) {
        textureName += "large_fern";
    } else if (blockType == mcpp::Blocks::ROSE_BUSH) {
        textureName += "rose_bush";
    } else if (blockType == mcpp::Blocks::PEONY) {
        textureName += "peony";
    } else if (blockType == mcpp::Blocks::FREESTANDING_BANNER) {
        textureName += "banner";
    } else if (blockType == mcpp::Blocks::WALLMOUNTED_BANNER) {
        textureName += "banner";
    } else if (blockType == mcpp::Blocks::INVERTED_DAYLIGHT_SENSOR) {
        textureName += "inverted_daylight_sensor";
    } else if (blockType == mcpp::Blocks::RED_SANDSTONE) {
        textureName += "red_sandstone";
    } else if (blockType == mcpp::Blocks::CHISELED_RED_SANDSTONE) {
        textureName += "chiseled_red_sandstone";
    } else if (blockType == mcpp::Blocks::SMOOTH_RED_SANDSTONE) {
        textureName += "smooth_red_sandstone";
    } else if (blockType == mcpp::Blocks::RED_SANDSTONE_STAIRS) {
        textureName += "red_sandstone";
    } else if (blockType == mcpp::Blocks::DOUBLE_RED_SANDSTONE_SLAB) {
        textureName += "red_sandstone";
    } else if (blockType == mcpp::Blocks::RED_SANDSTONE_SLAB) {
        textureName += "red_sandstone";
    } else if (blockType == mcpp::Blocks::SPRUCE_FENCE_GATE) {
        textureName += "spruce_wood_plank";
    } else if (blockType == mcpp::Blocks::BIRCH_FENCE_GATE) {
        textureName += "birch_wood_plank";
    } else if (blockType == mcpp::Blocks::JUNGLE_FENCE_GATE) {
        textureName += "jungle_wood_plank";
    } else if (blockType == mcpp::Blocks::DARK_OAK_FENCE_GATE) {
        textureName += "dark_oak_wood_plank";
    } else if (blockType == mcpp::Blocks::ACACIA_FENCE_GATE) {
        textureName += "acacia_wood_plank";
    } else if (blockType == mcpp::Blocks::SPRUCE_FENCE) {
        textureName += "spruce_wood_plank";
    } else if (blockType == mcpp::Blocks::BIRCH_FENCE) {
        textureName += "birch_wood_plank";
    } else if (blockType == mcpp::Blocks::JUNGLE_FENCE) {
        textureName += "jungle_wood_plank";
    } else if (blockType == mcpp::Blocks::DARK_OAK_FENCE) {
        textureName += "dark_oak_wood_plank";
    } else if (blockType == mcpp::Blocks::ACACIA_FENCE) {
        textureName += "acacia_wood_plank";
    } else if (blockType == mcpp::Blocks::SPRUCE_DOOR_BLOCK) {
        textureName += "door_spruce_upper";
    } else if (blockType == mcpp::Blocks::BIRCH_DOOR_BLOCK) {
        textureName += "door_birch_upper";
    } else if (blockType == mcpp::Blocks::JUNGLE_DOOR_BLOCK) {
        textureName += "door_jungle_upper";
    } else if (blockType == mcpp::Blocks::ACACIA_DOOR_BLOCK) {
        textureName += "door_acacia_upper";
    } else if (blockType == mcpp::Blocks::DARK_OAK_DOOR_BLOCK) {
        textureName += "door_dark_oak_upper";
    } else if (blockType == mcpp::Blocks::END_ROD) {
        textureName += "end_rod";
    } else if (blockType == mcpp::Blocks::CHORUS_PLANT) {
        textureName += "chorus_plant";
    } else if (blockType == mcpp::Blocks::CHORUS_FLOWER) {
        textureName += "chorus_flower";
    } else if (blockType == mcpp::Blocks::PURPUR_BLOCK) {
        textureName += "purpur_block";
    } else if (blockType == mcpp::Blocks::PURPUR_PILLAR) {
        textureName += "purpur_pillar";
    } else if (blockType == mcpp::Blocks::PURPUR_STAIRS) {
        textureName += "purpur_block";
    } else if (blockType == mcpp::Blocks::PURPUR_DOUBLE_SLAB) {
        textureName += "purpur_block";
    } else if (blockType == mcpp::Blocks::PURPUR_SLAB) {
        textureName += "purpur_block";
    } else if (blockType == mcpp::Blocks::END_STONE_BRICKS) {
        textureName += "end_stone_bricks";
    } else if (blockType == mcpp::Blocks::BEETROOT_BLOCK) {
        textureName += "beetroot_block";
    } else if (blockType == mcpp::Blocks::GRASS_PATH) {
        textureName += "grass_path";
    } else if (blockType == mcpp::Blocks::END_GATEWAY) {
        textureName += "end_portal";
    } else if (blockType == mcpp::Blocks::REPEATING_COMMAND_BLOCK) {
        textureName += "repeating_command_block";
    } else if (blockType == mcpp::Blocks::CHAIN_COMMAND_BLOCK) {
        textureName += "chain_command_block";
    } else if (blockType == mcpp::Blocks::FROSTED_ICE) {
        textureName += "frosted_ice";
    } else if (blockType == mcpp::Blocks::MAGMA_BLOCK) {
        textureName += "magma_block";
    } else if (blockType == mcpp::Blocks::NETHER_WART_BLOCK) {
        textureName += "nether_wart_block";
    } else if (blockType == mcpp::Blocks::RED_NETHER_BRICK) {
        textureName += "red_nether_brick";
    } else if (blockType == mcpp::Blocks::BONE_BLOCK) {
        textureName += "bone_block";
    } else if (blockType == mcpp::Blocks::STRUCTURE_VOID) {
        textureName += "structure_void";
    } else if (blockType == mcpp::Blocks::OBSERVER) {
        textureName += "observer";
    } else if (blockType == mcpp::Blocks::WHITE_SHULKER_BOX) {
        textureName += "white_shulker_box";
    } else if (blockType == mcpp::Blocks::ORANGE_SHULKER_BOX) {
        textureName += "orange_shulker_box";
    } else if (blockType == mcpp::Blocks::MAGENTA_SHULKER_BOX) {
        textureName += "magenta_shulker_box";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_SHULKER_BOX) {
        textureName += "light_blue_shulker_box";
    } else if (blockType == mcpp::Blocks::YELLOW_SHULKER_BOX) {
        textureName += "yellow_shulker_box";
    } else if (blockType == mcpp::Blocks::LIME_SHULKER_BOX) {
        textureName += "lime_shulker_box";
    } else if (blockType == mcpp::Blocks::PINK_SHULKER_BOX) {
        textureName += "pink_shulker_box";
    } else if (blockType == mcpp::Blocks::GRAY_SHULKER_BOX) {
        textureName += "gray_shulker_box";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_SHULKER_BOX) {
        textureName += "light_gray_shulker_box";
    } else if (blockType == mcpp::Blocks::CYAN_SHULKER_BOX) {
        textureName += "cyan_shulker_box";
    } else if (blockType == mcpp::Blocks::PURPLE_SHULKER_BOX) {
        textureName += "purple_shulker_box";
    } else if (blockType == mcpp::Blocks::BLUE_SHULKER_BOX) {
        textureName += "blue_shulker_box";
    } else if (blockType == mcpp::Blocks::BROWN_SHULKER_BOX) {
        textureName += "brown_shulker_box";
    } else if (blockType == mcpp::Blocks::GREEN_SHULKER_BOX) {
        textureName += "green_shulker_box";
    } else if (blockType == mcpp::Blocks::RED_SHULKER_BOX) {
        textureName += "red_shulker_box";
    } else if (blockType == mcpp::Blocks::BLACK_SHULKER_BOX) {
        textureName += "black_shulker_box";
    } else if (blockType == mcpp::Blocks::WHITE_GLAZED_TERRACOTTA) {
        textureName += "white_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::ORANGE_GLAZED_TERRACOTTA) {
        textureName += "orange_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::MAGENTA_GLAZED_TERRACOTTA) {
        textureName += "magenta_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_GLAZED_TERRACOTTA) {
        textureName += "light_blue_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::YELLOW_GLAZED_TERRACOTTA) {
        textureName += "yellow_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::LIME_GLAZED_TERRACOTTA) {
        textureName += "lime_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::PINK_GLAZED_TERRACOTTA) {
        textureName += "pink_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::GRAY_GLAZED_TERRACOTTA) {
        textureName += "gray_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_GLAZED_TERRACOTTA) {
        textureName += "light_gray_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::CYAN_GLAZED_TERRACOTTA) {
        textureName += "cyan_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::PURPLE_GLAZED_TERRACOTTA) {
        textureName += "purple_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::BLUE_GLAZED_TERRACOTTA) {
        textureName += "blue_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::BROWN_GLAZED_TERRACOTTA) {
        textureName += "brown_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::GREEN_GLAZED_TERRACOTTA) {
        textureName += "green_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::RED_GLAZED_TERRACOTTA) {
        textureName += "red_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::BLACK_GLAZED_TERRACOTTA) {
        textureName += "black_glazed_terracotta";
    } else if (blockType == mcpp::Blocks::WHITE_CONCRETE) {
        textureName += "white_concrete";
    } else if (blockType == mcpp::Blocks::ORANGE_CONCRETE) {
        textureName += "orange_concrete";
    } else if (blockType == mcpp::Blocks::MAGENTA_CONCRETE) {
        textureName += "magenta_concrete";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_CONCRETE) {
        textureName += "light_blue_concrete";
    } else if (blockType == mcpp::Blocks::YELLOW_CONCRETE) {
        textureName += "yellow_concrete";
    } else if (blockType == mcpp::Blocks::LIME_CONCRETE) {
        textureName += "lime_concrete";
    } else if (blockType == mcpp::Blocks::PINK_CONCRETE) {
        textureName += "pink_concrete";
    } else if (blockType == mcpp::Blocks::GRAY_CONCRETE) {
        textureName += "gray_concrete";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_CONCRETE) {
        textureName += "light_gray_concrete";
    } else if (blockType == mcpp::Blocks::CYAN_CONCRETE) {
        textureName += "cyan_concrete";
    } else if (blockType == mcpp::Blocks::PURPLE_CONCRETE) {
        textureName += "purple_concrete";
    } else if (blockType == mcpp::Blocks::BLUE_CONCRETE) {
        textureName += "blue_concrete";
    } else if (blockType == mcpp::Blocks::BROWN_CONCRETE) {
        textureName += "brown_concrete";
    } else if (blockType == mcpp::Blocks::GREEN_CONCRETE) {
        textureName += "green_concrete";
    } else if (blockType == mcpp::Blocks::RED_CONCRETE) {
        textureName += "red_concrete";
    } else if (blockType == mcpp::Blocks::BLACK_CONCRETE) {
        textureName += "black_concrete";
    } else if (blockType == mcpp::Blocks::WHITE_CONCRETE_POWDER) {
        textureName += "white_concrete_powder";
    } else if (blockType == mcpp::Blocks::ORANGE_CONCRETE_POWDER) {
        textureName += "orange_concrete_powder";
    } else if (blockType == mcpp::Blocks::MAGENTA_CONCRETE_POWDER) {
        textureName += "magenta_concrete_powder";
    } else if (blockType == mcpp::Blocks::LIGHT_BLUE_CONCRETE_POWDER) {
        textureName += "light_blue_concrete_powder";
    } else if (blockType == mcpp::Blocks::YELLOW_CONCRETE_POWDER) {
        textureName += "yellow_concrete_powder";
    } else if (blockType == mcpp::Blocks::LIME_CONCRETE_POWDER) {
        textureName += "lime_concrete_powder";
    } else if (blockType == mcpp::Blocks::PINK_CONCRETE_POWDER) {
        textureName += "pink_concrete_powder";
    } else if (blockType == mcpp::Blocks::GRAY_CONCRETE_POWDER) {
        textureName += "gray_concrete_powder";
    } else if (blockType == mcpp::Blocks::LIGHT_GRAY_CONCRETE_POWDER) {
        textureName += "light_gray_concrete_powder";
    } else if (blockType == mcpp::Blocks::CYAN_CONCRETE_POWDER) {
        textureName += "cyan_concrete_powder";
    } else if (blockType == mcpp::Blocks::PURPLE_CONCRETE_POWDER) {
        textureName += "purple_concrete_powder";
    } else if (blockType == mcpp::Blocks::BLUE_CONCRETE_POWDER) {
        textureName += "blue_concrete_powder";
    } else if (blockType == mcpp::Blocks::BROWN_CONCRETE_POWDER) {
        textureName += "brown_concrete_powder";
    } else if (blockType == mcpp::Blocks::GREEN_CONCRETE_POWDER) {
        textureName += "green_concrete_powder";
    } else if (blockType == mcpp::Blocks::RED_CONCRETE_POWDER) {
        textureName += "red_concrete_powder";
    } else if (blockType == mcpp::Blocks::BLACK_CONCRETE_POWDER) {
        textureName += "black_concrete_powder";
    } else if (blockType == mcpp::Blocks::STRUCTURE_BLOCK) {
        textureName += "structure_block";
    } else {
        WARN("Failed to load: " << blockType.id << " " << blockType.mod);
        textureName += "error";
    }

    textureName += ".png";

    return textureName;
}

std::vector<std::pair<mcpp::Coordinate, mcpp::BlockType>> getAllBlocks() {
    return {
        {mcpp::Coordinate(0, 20, 0), mcpp::BlockType(0)},
        {mcpp::Coordinate(1, 20, 0), mcpp::BlockType(1)},
        {mcpp::Coordinate(1, 20, 1), mcpp::BlockType(1, 1)},
        {mcpp::Coordinate(1, 20, 2), mcpp::BlockType(1, 2)},
        {mcpp::Coordinate(1, 20, 3), mcpp::BlockType(1, 3)},
        {mcpp::Coordinate(1, 20, 4), mcpp::BlockType(1, 4)},
        {mcpp::Coordinate(1, 20, 5), mcpp::BlockType(1, 5)},
        {mcpp::Coordinate(1, 20, 6), mcpp::BlockType(1, 6)},
        {mcpp::Coordinate(2, 20, 0), mcpp::BlockType(2)},
        {mcpp::Coordinate(3, 20, 0), mcpp::BlockType(3)},
        {mcpp::Coordinate(3, 20, 1), mcpp::BlockType(3, 1)},
        {mcpp::Coordinate(3, 20, 2), mcpp::BlockType(3, 2)},
        {mcpp::Coordinate(4, 20, 0), mcpp::BlockType(4)},
        {mcpp::Coordinate(5, 20, 0), mcpp::BlockType(5)},
        {mcpp::Coordinate(5, 20, 1), mcpp::BlockType(5, 1)},
        {mcpp::Coordinate(5, 20, 2), mcpp::BlockType(5, 2)},
        {mcpp::Coordinate(5, 20, 3), mcpp::BlockType(5, 3)},
        {mcpp::Coordinate(5, 20, 4), mcpp::BlockType(5, 4)},
        {mcpp::Coordinate(5, 20, 5), mcpp::BlockType(5, 5)},
        {mcpp::Coordinate(6, 20, 0), mcpp::BlockType(6)},
        {mcpp::Coordinate(6, 20, 1), mcpp::BlockType(6, 1)},
        {mcpp::Coordinate(6, 20, 2), mcpp::BlockType(6, 2)},
        {mcpp::Coordinate(6, 20, 3), mcpp::BlockType(6, 3)},
        {mcpp::Coordinate(6, 20, 4), mcpp::BlockType(6, 4)},
        {mcpp::Coordinate(6, 20, 5), mcpp::BlockType(6, 5)},
        {mcpp::Coordinate(7, 20, 0), mcpp::BlockType(7)},
        {mcpp::Coordinate(8, 20, 0), mcpp::BlockType(8)},
        {mcpp::Coordinate(9, 20, 0), mcpp::BlockType(9)},
        {mcpp::Coordinate(10, 20, 0), mcpp::BlockType(10)},
        {mcpp::Coordinate(11, 20, 0), mcpp::BlockType(11)},
        {mcpp::Coordinate(12, 20, 0), mcpp::BlockType(12)},
        {mcpp::Coordinate(12, 20, 1), mcpp::BlockType(12, 1)},
        {mcpp::Coordinate(13, 20, 0), mcpp::BlockType(13)},
        {mcpp::Coordinate(14, 20, 0), mcpp::BlockType(14)},
        {mcpp::Coordinate(15, 20, 0), mcpp::BlockType(15)},
        {mcpp::Coordinate(16, 20, 0), mcpp::BlockType(16)},
        {mcpp::Coordinate(17, 20, 0), mcpp::BlockType(17)},
        {mcpp::Coordinate(17, 20, 1), mcpp::BlockType(17, 1)},
        {mcpp::Coordinate(17, 20, 2), mcpp::BlockType(17, 2)},
        {mcpp::Coordinate(17, 20, 3), mcpp::BlockType(17, 3)},
        {mcpp::Coordinate(18, 20, 0), mcpp::BlockType(18)},
        {mcpp::Coordinate(18, 20, 1), mcpp::BlockType(18, 1)},
        {mcpp::Coordinate(18, 20, 2), mcpp::BlockType(18, 2)},
        {mcpp::Coordinate(18, 20, 3), mcpp::BlockType(18, 3)},
        {mcpp::Coordinate(19, 20, 0), mcpp::BlockType(19)},
        {mcpp::Coordinate(19, 20, 1), mcpp::BlockType(19, 1)},
        {mcpp::Coordinate(20, 20, 0), mcpp::BlockType(20)},
        {mcpp::Coordinate(21, 20, 0), mcpp::BlockType(21)},
        {mcpp::Coordinate(22, 20, 0), mcpp::BlockType(22)},
        {mcpp::Coordinate(23, 20, 0), mcpp::BlockType(23)},
        {mcpp::Coordinate(24, 20, 0), mcpp::BlockType(24)},
        {mcpp::Coordinate(24, 20, 1), mcpp::BlockType(24, 1)},
        {mcpp::Coordinate(24, 20, 2), mcpp::BlockType(24, 2)},
        {mcpp::Coordinate(25, 20, 0), mcpp::BlockType(25)},
        {mcpp::Coordinate(26, 20, 0), mcpp::BlockType(26)},
        {mcpp::Coordinate(27, 20, 0), mcpp::BlockType(27)},
        {mcpp::Coordinate(28, 20, 0), mcpp::BlockType(28)},
        {mcpp::Coordinate(29, 20, 0), mcpp::BlockType(29)},
        {mcpp::Coordinate(30, 20, 0), mcpp::BlockType(30)},
        {mcpp::Coordinate(31, 20, 0), mcpp::BlockType(31)},
        {mcpp::Coordinate(31, 20, 1), mcpp::BlockType(31, 1)},
        {mcpp::Coordinate(31, 20, 2), mcpp::BlockType(31, 2)},
        {mcpp::Coordinate(32, 20, 0), mcpp::BlockType(32)},
        {mcpp::Coordinate(33, 20, 0), mcpp::BlockType(33)},
        {mcpp::Coordinate(34, 20, 0), mcpp::BlockType(34)},
        {mcpp::Coordinate(35, 20, 0), mcpp::BlockType(35)},
        {mcpp::Coordinate(35, 20, 1), mcpp::BlockType(35, 1)},
        {mcpp::Coordinate(35, 20, 2), mcpp::BlockType(35, 2)},
        {mcpp::Coordinate(35, 20, 3), mcpp::BlockType(35, 3)},
        {mcpp::Coordinate(35, 20, 4), mcpp::BlockType(35, 4)},
        {mcpp::Coordinate(35, 20, 5), mcpp::BlockType(35, 5)},
        {mcpp::Coordinate(35, 20, 6), mcpp::BlockType(35, 6)},
        {mcpp::Coordinate(35, 20, 7), mcpp::BlockType(35, 7)},
        {mcpp::Coordinate(35, 20, 8), mcpp::BlockType(35, 8)},
        {mcpp::Coordinate(35, 20, 9), mcpp::BlockType(35, 9)},
        {mcpp::Coordinate(35, 20, 10), mcpp::BlockType(35, 10)},
        {mcpp::Coordinate(35, 20, 11), mcpp::BlockType(35, 11)},
        {mcpp::Coordinate(35, 20, 12), mcpp::BlockType(35, 12)},
        {mcpp::Coordinate(35, 20, 13), mcpp::BlockType(35, 13)},
        {mcpp::Coordinate(35, 20, 14), mcpp::BlockType(35, 14)},
        {mcpp::Coordinate(35, 20, 15), mcpp::BlockType(35, 15)},
        {mcpp::Coordinate(37, 20, 0), mcpp::BlockType(37)},
        {mcpp::Coordinate(38, 20, 0), mcpp::BlockType(38)},
        {mcpp::Coordinate(38, 20, 1), mcpp::BlockType(38, 1)},
        {mcpp::Coordinate(38, 20, 2), mcpp::BlockType(38, 2)},
        {mcpp::Coordinate(38, 20, 3), mcpp::BlockType(38, 3)},
        {mcpp::Coordinate(38, 20, 4), mcpp::BlockType(38, 4)},
        {mcpp::Coordinate(38, 20, 5), mcpp::BlockType(38, 5)},
        {mcpp::Coordinate(38, 20, 6), mcpp::BlockType(38, 6)},
        {mcpp::Coordinate(38, 20, 7), mcpp::BlockType(38, 7)},
        {mcpp::Coordinate(38, 20, 8), mcpp::BlockType(38, 8)},
        {mcpp::Coordinate(39, 20, 0), mcpp::BlockType(39)},
        {mcpp::Coordinate(40, 20, 0), mcpp::BlockType(40)},
        {mcpp::Coordinate(41, 20, 0), mcpp::BlockType(41)},
        {mcpp::Coordinate(42, 20, 0), mcpp::BlockType(42)},
        {mcpp::Coordinate(43, 20, 0), mcpp::BlockType(43)},
        {mcpp::Coordinate(43, 20, 1), mcpp::BlockType(43, 1)},
        {mcpp::Coordinate(43, 20, 2), mcpp::BlockType(43, 2)},
        {mcpp::Coordinate(43, 20, 3), mcpp::BlockType(43, 3)},
        {mcpp::Coordinate(43, 20, 4), mcpp::BlockType(43, 4)},
        {mcpp::Coordinate(43, 20, 5), mcpp::BlockType(43, 5)},
        {mcpp::Coordinate(43, 20, 6), mcpp::BlockType(43, 6)},
        {mcpp::Coordinate(43, 20, 7), mcpp::BlockType(43, 7)},
        {mcpp::Coordinate(44, 20, 0), mcpp::BlockType(44)},
        {mcpp::Coordinate(44, 20, 1), mcpp::BlockType(44, 1)},
        {mcpp::Coordinate(44, 20, 2), mcpp::BlockType(44, 2)},
        {mcpp::Coordinate(44, 20, 3), mcpp::BlockType(44, 3)},
        {mcpp::Coordinate(44, 20, 4), mcpp::BlockType(44, 4)},
        {mcpp::Coordinate(44, 20, 5), mcpp::BlockType(44, 5)},
        {mcpp::Coordinate(44, 20, 6), mcpp::BlockType(44, 6)},
        {mcpp::Coordinate(44, 20, 7), mcpp::BlockType(44, 7)},
        {mcpp::Coordinate(45, 20, 0), mcpp::BlockType(45)},
        {mcpp::Coordinate(46, 20, 0), mcpp::BlockType(46)},
        {mcpp::Coordinate(47, 20, 0), mcpp::BlockType(47)},
        {mcpp::Coordinate(48, 20, 0), mcpp::BlockType(48)},
        {mcpp::Coordinate(49, 20, 0), mcpp::BlockType(49)},
        {mcpp::Coordinate(50, 20, 0), mcpp::BlockType(50)},
        {mcpp::Coordinate(51, 20, 0), mcpp::BlockType(51)},
        {mcpp::Coordinate(52, 20, 0), mcpp::BlockType(52)},
        {mcpp::Coordinate(53, 20, 0), mcpp::BlockType(53)},
        {mcpp::Coordinate(54, 20, 0), mcpp::BlockType(54)},
        {mcpp::Coordinate(55, 20, 0), mcpp::BlockType(55)},
        {mcpp::Coordinate(56, 20, 0), mcpp::BlockType(56)},
        {mcpp::Coordinate(57, 20, 0), mcpp::BlockType(57)},
        {mcpp::Coordinate(58, 20, 0), mcpp::BlockType(58)},
        {mcpp::Coordinate(59, 20, 0), mcpp::BlockType(59)},
        {mcpp::Coordinate(60, 20, 0), mcpp::BlockType(60)},
        {mcpp::Coordinate(61, 20, 0), mcpp::BlockType(61)},
        {mcpp::Coordinate(62, 20, 0), mcpp::BlockType(62)},
        {mcpp::Coordinate(63, 20, 0), mcpp::BlockType(63)},
        {mcpp::Coordinate(64, 20, 0), mcpp::BlockType(64)},
        {mcpp::Coordinate(65, 20, 0), mcpp::BlockType(65)},
        {mcpp::Coordinate(66, 20, 0), mcpp::BlockType(66)},
        {mcpp::Coordinate(67, 20, 0), mcpp::BlockType(67)},
        {mcpp::Coordinate(68, 20, 0), mcpp::BlockType(68)},
        {mcpp::Coordinate(69, 20, 0), mcpp::BlockType(69)},
        {mcpp::Coordinate(70, 20, 0), mcpp::BlockType(70)},
        {mcpp::Coordinate(71, 20, 0), mcpp::BlockType(71)},
        {mcpp::Coordinate(72, 20, 0), mcpp::BlockType(72)},
        {mcpp::Coordinate(73, 20, 0), mcpp::BlockType(73)},
        {mcpp::Coordinate(74, 20, 0), mcpp::BlockType(74)},
        {mcpp::Coordinate(75, 20, 0), mcpp::BlockType(75)},
        {mcpp::Coordinate(76, 20, 0), mcpp::BlockType(76)},
        {mcpp::Coordinate(77, 20, 0), mcpp::BlockType(77)},
        {mcpp::Coordinate(78, 20, 0), mcpp::BlockType(78)},
        {mcpp::Coordinate(79, 20, 0), mcpp::BlockType(79)},
        {mcpp::Coordinate(80, 20, 0), mcpp::BlockType(80)},
        {mcpp::Coordinate(81, 20, 0), mcpp::BlockType(81)},
        {mcpp::Coordinate(82, 20, 0), mcpp::BlockType(82)},
        {mcpp::Coordinate(83, 20, 0), mcpp::BlockType(83)},
        {mcpp::Coordinate(84, 20, 0), mcpp::BlockType(84)},
        {mcpp::Coordinate(85, 20, 0), mcpp::BlockType(85)},
        {mcpp::Coordinate(86, 20, 0), mcpp::BlockType(86)},
        {mcpp::Coordinate(87, 20, 0), mcpp::BlockType(87)},
        {mcpp::Coordinate(88, 20, 0), mcpp::BlockType(88)},
        {mcpp::Coordinate(89, 20, 0), mcpp::BlockType(89)},
        {mcpp::Coordinate(90, 20, 0), mcpp::BlockType(90)},
        {mcpp::Coordinate(91, 20, 0), mcpp::BlockType(91)},
        {mcpp::Coordinate(92, 20, 0), mcpp::BlockType(92)},
        {mcpp::Coordinate(93, 20, 0), mcpp::BlockType(93)},
        {mcpp::Coordinate(94, 20, 0), mcpp::BlockType(94)},
        {mcpp::Coordinate(95, 20, 0), mcpp::BlockType(95)},
        {mcpp::Coordinate(95, 20, 1), mcpp::BlockType(95, 1)},
        {mcpp::Coordinate(95, 20, 2), mcpp::BlockType(95, 2)},
        {mcpp::Coordinate(95, 20, 3), mcpp::BlockType(95, 3)},
        {mcpp::Coordinate(95, 20, 4), mcpp::BlockType(95, 4)},
        {mcpp::Coordinate(95, 20, 5), mcpp::BlockType(95, 5)},
        {mcpp::Coordinate(95, 20, 6), mcpp::BlockType(95, 6)},
        {mcpp::Coordinate(95, 20, 7), mcpp::BlockType(95, 7)},
        {mcpp::Coordinate(95, 20, 8), mcpp::BlockType(95, 8)},
        {mcpp::Coordinate(95, 20, 9), mcpp::BlockType(95, 9)},
        {mcpp::Coordinate(95, 20, 10), mcpp::BlockType(95, 10)},
        {mcpp::Coordinate(95, 20, 11), mcpp::BlockType(95, 11)},
        {mcpp::Coordinate(95, 20, 12), mcpp::BlockType(95, 12)},
        {mcpp::Coordinate(95, 20, 13), mcpp::BlockType(95, 13)},
        {mcpp::Coordinate(95, 20, 14), mcpp::BlockType(95, 14)},
        {mcpp::Coordinate(95, 20, 15), mcpp::BlockType(95, 15)},
        {mcpp::Coordinate(96, 20, 0), mcpp::BlockType(96)},
        {mcpp::Coordinate(97, 20, 0), mcpp::BlockType(97)},
        {mcpp::Coordinate(97, 20, 1), mcpp::BlockType(97, 1)},
        {mcpp::Coordinate(97, 20, 2), mcpp::BlockType(97, 2)},
        {mcpp::Coordinate(97, 20, 3), mcpp::BlockType(97, 3)},
        {mcpp::Coordinate(97, 20, 4), mcpp::BlockType(97, 4)},
        {mcpp::Coordinate(97, 20, 5), mcpp::BlockType(97, 5)},
        {mcpp::Coordinate(98, 20, 0), mcpp::BlockType(98)},
        {mcpp::Coordinate(98, 20, 1), mcpp::BlockType(98, 1)},
        {mcpp::Coordinate(98, 20, 2), mcpp::BlockType(98, 2)},
        {mcpp::Coordinate(98, 20, 3), mcpp::BlockType(98, 3)},
        {mcpp::Coordinate(99, 20, 0), mcpp::BlockType(99)},
        {mcpp::Coordinate(100, 20, 0), mcpp::BlockType(100)},
        {mcpp::Coordinate(101, 20, 0), mcpp::BlockType(101)},
        {mcpp::Coordinate(102, 20, 0), mcpp::BlockType(102)},
        {mcpp::Coordinate(103, 20, 0), mcpp::BlockType(103)},
        {mcpp::Coordinate(104, 20, 0), mcpp::BlockType(104)},
        {mcpp::Coordinate(105, 20, 0), mcpp::BlockType(105)},
        {mcpp::Coordinate(106, 20, 0), mcpp::BlockType(106)},
        {mcpp::Coordinate(107, 20, 0), mcpp::BlockType(107)},
        {mcpp::Coordinate(108, 20, 0), mcpp::BlockType(108)},
        {mcpp::Coordinate(109, 20, 0), mcpp::BlockType(109)},
        {mcpp::Coordinate(110, 20, 0), mcpp::BlockType(110)},
        {mcpp::Coordinate(111, 20, 0), mcpp::BlockType(111)},
        {mcpp::Coordinate(112, 20, 0), mcpp::BlockType(112)},
        {mcpp::Coordinate(113, 20, 0), mcpp::BlockType(113)},
        {mcpp::Coordinate(114, 20, 0), mcpp::BlockType(114)},
        {mcpp::Coordinate(115, 20, 0), mcpp::BlockType(115)},
        {mcpp::Coordinate(116, 20, 0), mcpp::BlockType(116)},
        {mcpp::Coordinate(117, 20, 0), mcpp::BlockType(117)},
        {mcpp::Coordinate(118, 20, 0), mcpp::BlockType(118)},
        {mcpp::Coordinate(119, 20, 0), mcpp::BlockType(119)},
        {mcpp::Coordinate(120, 20, 0), mcpp::BlockType(120)},
        {mcpp::Coordinate(121, 20, 0), mcpp::BlockType(121)},
        {mcpp::Coordinate(122, 20, 0), mcpp::BlockType(122)},
        {mcpp::Coordinate(123, 20, 0), mcpp::BlockType(123)},
        {mcpp::Coordinate(124, 20, 0), mcpp::BlockType(124)},
        {mcpp::Coordinate(125, 20, 0), mcpp::BlockType(125)},
        {mcpp::Coordinate(125, 20, 1), mcpp::BlockType(125, 1)},
        {mcpp::Coordinate(125, 20, 2), mcpp::BlockType(125, 2)},
        {mcpp::Coordinate(125, 20, 3), mcpp::BlockType(125, 3)},
        {mcpp::Coordinate(125, 20, 4), mcpp::BlockType(125, 4)},
        {mcpp::Coordinate(125, 20, 5), mcpp::BlockType(125, 5)},
        {mcpp::Coordinate(126, 20, 0), mcpp::BlockType(126)},
        {mcpp::Coordinate(126, 20, 1), mcpp::BlockType(126, 1)},
        {mcpp::Coordinate(126, 20, 2), mcpp::BlockType(126, 2)},
        {mcpp::Coordinate(126, 20, 3), mcpp::BlockType(126, 3)},
        {mcpp::Coordinate(126, 20, 4), mcpp::BlockType(126, 4)},
        {mcpp::Coordinate(126, 20, 5), mcpp::BlockType(126, 5)},
        {mcpp::Coordinate(127, 20, 0), mcpp::BlockType(127)},
        {mcpp::Coordinate(128, 20, 0), mcpp::BlockType(128)},
        {mcpp::Coordinate(129, 20, 0), mcpp::BlockType(129)},
        {mcpp::Coordinate(130, 20, 0), mcpp::BlockType(130)},
        {mcpp::Coordinate(131, 20, 0), mcpp::BlockType(131)},
        {mcpp::Coordinate(132, 20, 0), mcpp::BlockType(132)},
        {mcpp::Coordinate(133, 20, 0), mcpp::BlockType(133)},
        {mcpp::Coordinate(134, 20, 0), mcpp::BlockType(134)},
        {mcpp::Coordinate(135, 20, 0), mcpp::BlockType(135)},
        {mcpp::Coordinate(136, 20, 0), mcpp::BlockType(136)},
        {mcpp::Coordinate(137, 20, 0), mcpp::BlockType(137)},
        {mcpp::Coordinate(138, 20, 0), mcpp::BlockType(138)},
        {mcpp::Coordinate(139, 20, 0), mcpp::BlockType(139)},
        {mcpp::Coordinate(139, 20, 1), mcpp::BlockType(139, 1)},
        {mcpp::Coordinate(140, 20, 0), mcpp::BlockType(140)},
        {mcpp::Coordinate(141, 20, 0), mcpp::BlockType(141)},
        {mcpp::Coordinate(142, 20, 0), mcpp::BlockType(142)},
        {mcpp::Coordinate(143, 20, 0), mcpp::BlockType(143)},
        {mcpp::Coordinate(144, 20, 0), mcpp::BlockType(144)},
        {mcpp::Coordinate(145, 20, 0), mcpp::BlockType(145)},
        {mcpp::Coordinate(146, 20, 0), mcpp::BlockType(146)},
        {mcpp::Coordinate(147, 20, 0), mcpp::BlockType(147)},
        {mcpp::Coordinate(148, 20, 0), mcpp::BlockType(148)},
        {mcpp::Coordinate(149, 20, 0), mcpp::BlockType(149)},
        {mcpp::Coordinate(150, 20, 0), mcpp::BlockType(150)},
        {mcpp::Coordinate(151, 20, 0), mcpp::BlockType(151)},
        {mcpp::Coordinate(152, 20, 0), mcpp::BlockType(152)},
        {mcpp::Coordinate(153, 20, 0), mcpp::BlockType(153)},
        {mcpp::Coordinate(154, 20, 0), mcpp::BlockType(154)},
        {mcpp::Coordinate(155, 20, 0), mcpp::BlockType(155)},
        {mcpp::Coordinate(155, 20, 1), mcpp::BlockType(155, 1)},
        {mcpp::Coordinate(155, 20, 2), mcpp::BlockType(155, 2)},
        {mcpp::Coordinate(156, 20, 0), mcpp::BlockType(156)},
        {mcpp::Coordinate(157, 20, 0), mcpp::BlockType(157)},
        {mcpp::Coordinate(158, 20, 0), mcpp::BlockType(158)},
        {mcpp::Coordinate(159, 20, 0), mcpp::BlockType(159)},
        {mcpp::Coordinate(159, 20, 1), mcpp::BlockType(159, 1)},
        {mcpp::Coordinate(159, 20, 2), mcpp::BlockType(159, 2)},
        {mcpp::Coordinate(159, 20, 3), mcpp::BlockType(159, 3)},
        {mcpp::Coordinate(159, 20, 4), mcpp::BlockType(159, 4)},
        {mcpp::Coordinate(159, 20, 5), mcpp::BlockType(159, 5)},
        {mcpp::Coordinate(159, 20, 6), mcpp::BlockType(159, 6)},
        {mcpp::Coordinate(159, 20, 7), mcpp::BlockType(159, 7)},
        {mcpp::Coordinate(159, 20, 8), mcpp::BlockType(159, 8)},
        {mcpp::Coordinate(159, 20, 9), mcpp::BlockType(159, 9)},
        {mcpp::Coordinate(159, 20, 10), mcpp::BlockType(159, 10)},
        {mcpp::Coordinate(159, 20, 11), mcpp::BlockType(159, 11)},
        {mcpp::Coordinate(159, 20, 12), mcpp::BlockType(159, 12)},
        {mcpp::Coordinate(159, 20, 13), mcpp::BlockType(159, 13)},
        {mcpp::Coordinate(159, 20, 14), mcpp::BlockType(159, 14)},
        {mcpp::Coordinate(159, 20, 15), mcpp::BlockType(159, 15)},
        {mcpp::Coordinate(160, 20, 0), mcpp::BlockType(160)},
        {mcpp::Coordinate(160, 20, 1), mcpp::BlockType(160, 1)},
        {mcpp::Coordinate(160, 20, 2), mcpp::BlockType(160, 2)},
        {mcpp::Coordinate(160, 20, 3), mcpp::BlockType(160, 3)},
        {mcpp::Coordinate(160, 20, 4), mcpp::BlockType(160, 4)},
        {mcpp::Coordinate(160, 20, 5), mcpp::BlockType(160, 5)},
        {mcpp::Coordinate(160, 20, 6), mcpp::BlockType(160, 6)},
        {mcpp::Coordinate(160, 20, 7), mcpp::BlockType(160, 7)},
        {mcpp::Coordinate(160, 20, 8), mcpp::BlockType(160, 8)},
        {mcpp::Coordinate(160, 20, 9), mcpp::BlockType(160, 9)},
        {mcpp::Coordinate(160, 20, 10), mcpp::BlockType(160, 10)},
        {mcpp::Coordinate(160, 20, 11), mcpp::BlockType(160, 11)},
        {mcpp::Coordinate(160, 20, 12), mcpp::BlockType(160, 12)},
        {mcpp::Coordinate(160, 20, 13), mcpp::BlockType(160, 13)},
        {mcpp::Coordinate(160, 20, 14), mcpp::BlockType(160, 14)},
        {mcpp::Coordinate(160, 20, 15), mcpp::BlockType(160, 15)},
        {mcpp::Coordinate(161, 20, 0), mcpp::BlockType(161)},
        {mcpp::Coordinate(161, 20, 1), mcpp::BlockType(161, 1)},
        {mcpp::Coordinate(162, 20, 0), mcpp::BlockType(162)},
        {mcpp::Coordinate(162, 20, 1), mcpp::BlockType(162, 1)},
        {mcpp::Coordinate(163, 20, 0), mcpp::BlockType(163)},
        {mcpp::Coordinate(164, 20, 0), mcpp::BlockType(164)},
        {mcpp::Coordinate(165, 20, 0), mcpp::BlockType(165)},
        {mcpp::Coordinate(166, 20, 0), mcpp::BlockType(166)},
        {mcpp::Coordinate(167, 20, 0), mcpp::BlockType(167)},
        {mcpp::Coordinate(168, 20, 0), mcpp::BlockType(168)},
        {mcpp::Coordinate(168, 20, 1), mcpp::BlockType(168, 1)},
        {mcpp::Coordinate(168, 20, 2), mcpp::BlockType(168, 2)},
        {mcpp::Coordinate(169, 20, 0), mcpp::BlockType(169)},
        {mcpp::Coordinate(170, 20, 0), mcpp::BlockType(170)},
        {mcpp::Coordinate(171, 20, 0), mcpp::BlockType(171)},
        {mcpp::Coordinate(171, 20, 1), mcpp::BlockType(171, 1)},
        {mcpp::Coordinate(171, 20, 2), mcpp::BlockType(171, 2)},
        {mcpp::Coordinate(171, 20, 3), mcpp::BlockType(171, 3)},
        {mcpp::Coordinate(171, 20, 4), mcpp::BlockType(171, 4)},
        {mcpp::Coordinate(171, 20, 5), mcpp::BlockType(171, 5)},
        {mcpp::Coordinate(171, 20, 6), mcpp::BlockType(171, 6)},
        {mcpp::Coordinate(171, 20, 7), mcpp::BlockType(171, 7)},
        {mcpp::Coordinate(171, 20, 8), mcpp::BlockType(171, 8)},
        {mcpp::Coordinate(171, 20, 9), mcpp::BlockType(171, 9)},
        {mcpp::Coordinate(171, 20, 10), mcpp::BlockType(171, 10)},
        {mcpp::Coordinate(171, 20, 11), mcpp::BlockType(171, 11)},
        {mcpp::Coordinate(171, 20, 12), mcpp::BlockType(171, 12)},
        {mcpp::Coordinate(171, 20, 13), mcpp::BlockType(171, 13)},
        {mcpp::Coordinate(171, 20, 14), mcpp::BlockType(171, 14)},
        {mcpp::Coordinate(171, 20, 15), mcpp::BlockType(171, 15)},
        {mcpp::Coordinate(172, 20, 0), mcpp::BlockType(172)},
        {mcpp::Coordinate(173, 20, 0), mcpp::BlockType(173)},
        {mcpp::Coordinate(174, 20, 0), mcpp::BlockType(174)},
        {mcpp::Coordinate(175, 20, 0), mcpp::BlockType(175)},
        {mcpp::Coordinate(175, 20, 1), mcpp::BlockType(175, 1)},
        {mcpp::Coordinate(175, 20, 2), mcpp::BlockType(175, 2)},
        {mcpp::Coordinate(175, 20, 3), mcpp::BlockType(175, 3)},
        {mcpp::Coordinate(175, 20, 4), mcpp::BlockType(175, 4)},
        {mcpp::Coordinate(175, 20, 5), mcpp::BlockType(175, 5)},
        {mcpp::Coordinate(176, 20, 0), mcpp::BlockType(176)},
        {mcpp::Coordinate(177, 20, 0), mcpp::BlockType(177)},
        {mcpp::Coordinate(178, 20, 0), mcpp::BlockType(178)},
        {mcpp::Coordinate(179, 20, 0), mcpp::BlockType(179)},
        {mcpp::Coordinate(179, 20, 1), mcpp::BlockType(179, 1)},
        {mcpp::Coordinate(179, 20, 2), mcpp::BlockType(179, 2)},
        {mcpp::Coordinate(180, 20, 0), mcpp::BlockType(180)},
        {mcpp::Coordinate(181, 20, 0), mcpp::BlockType(181)},
        {mcpp::Coordinate(182, 20, 0), mcpp::BlockType(182)},
        {mcpp::Coordinate(183, 20, 0), mcpp::BlockType(183)},
        {mcpp::Coordinate(184, 20, 0), mcpp::BlockType(184)},
        {mcpp::Coordinate(185, 20, 0), mcpp::BlockType(185)},
        {mcpp::Coordinate(186, 20, 0), mcpp::BlockType(186)},
        {mcpp::Coordinate(187, 20, 0), mcpp::BlockType(187)},
        {mcpp::Coordinate(188, 20, 0), mcpp::BlockType(188)},
        {mcpp::Coordinate(189, 20, 0), mcpp::BlockType(189)},
        {mcpp::Coordinate(190, 20, 0), mcpp::BlockType(190)},
        {mcpp::Coordinate(191, 20, 0), mcpp::BlockType(191)},
        {mcpp::Coordinate(192, 20, 0), mcpp::BlockType(192)},
        {mcpp::Coordinate(193, 20, 0), mcpp::BlockType(193)},
        {mcpp::Coordinate(194, 20, 0), mcpp::BlockType(194)},
        {mcpp::Coordinate(195, 20, 0), mcpp::BlockType(195)},
        {mcpp::Coordinate(196, 20, 0), mcpp::BlockType(196)},
        {mcpp::Coordinate(197, 20, 0), mcpp::BlockType(197)},
        {mcpp::Coordinate(198, 20, 0), mcpp::BlockType(198)},
        {mcpp::Coordinate(199, 20, 0), mcpp::BlockType(199)},
        {mcpp::Coordinate(200, 20, 0), mcpp::BlockType(200)},
        {mcpp::Coordinate(201, 20, 0), mcpp::BlockType(201)},
        {mcpp::Coordinate(202, 20, 0), mcpp::BlockType(202)},
        {mcpp::Coordinate(203, 20, 0), mcpp::BlockType(203)},
        {mcpp::Coordinate(204, 20, 0), mcpp::BlockType(204)},
        {mcpp::Coordinate(205, 20, 0), mcpp::BlockType(205)},
        {mcpp::Coordinate(206, 20, 0), mcpp::BlockType(206)},
        {mcpp::Coordinate(207, 20, 0), mcpp::BlockType(207)},
        {mcpp::Coordinate(208, 20, 0), mcpp::BlockType(208)},
        {mcpp::Coordinate(209, 20, 0), mcpp::BlockType(209)},
        {mcpp::Coordinate(210, 20, 0), mcpp::BlockType(210)},
        {mcpp::Coordinate(211, 20, 0), mcpp::BlockType(211)},
        {mcpp::Coordinate(212, 20, 0), mcpp::BlockType(212)},
        {mcpp::Coordinate(213, 20, 0), mcpp::BlockType(213)},
        {mcpp::Coordinate(214, 20, 0), mcpp::BlockType(214)},
        {mcpp::Coordinate(215, 20, 0), mcpp::BlockType(215)},
        {mcpp::Coordinate(216, 20, 0), mcpp::BlockType(216)},
        {mcpp::Coordinate(217, 20, 0), mcpp::BlockType(217)},
        {mcpp::Coordinate(218, 20, 0), mcpp::BlockType(218)},
        {mcpp::Coordinate(219, 20, 0), mcpp::BlockType(219)},
        {mcpp::Coordinate(220, 20, 0), mcpp::BlockType(220)},
        {mcpp::Coordinate(221, 20, 0), mcpp::BlockType(221)},
        {mcpp::Coordinate(222, 20, 0), mcpp::BlockType(222)},
        {mcpp::Coordinate(223, 20, 0), mcpp::BlockType(223)},
        {mcpp::Coordinate(224, 20, 0), mcpp::BlockType(224)},
        {mcpp::Coordinate(225, 20, 0), mcpp::BlockType(225)},
        {mcpp::Coordinate(226, 20, 0), mcpp::BlockType(226)},
        {mcpp::Coordinate(227, 20, 0), mcpp::BlockType(227)},
        {mcpp::Coordinate(228, 20, 0), mcpp::BlockType(228)},
        {mcpp::Coordinate(229, 20, 0), mcpp::BlockType(229)},
        {mcpp::Coordinate(230, 20, 0), mcpp::BlockType(230)},
        {mcpp::Coordinate(231, 20, 0), mcpp::BlockType(231)},
        {mcpp::Coordinate(232, 20, 0), mcpp::BlockType(232)},
        {mcpp::Coordinate(233, 20, 0), mcpp::BlockType(233)},
        {mcpp::Coordinate(234, 20, 0), mcpp::BlockType(234)},
        {mcpp::Coordinate(235, 20, 0), mcpp::BlockType(235)},
        {mcpp::Coordinate(236, 20, 0), mcpp::BlockType(236)},
        {mcpp::Coordinate(237, 20, 0), mcpp::BlockType(237)},
        {mcpp::Coordinate(238, 20, 0), mcpp::BlockType(238)},
        {mcpp::Coordinate(239, 20, 0), mcpp::BlockType(239)},
        {mcpp::Coordinate(240, 20, 0), mcpp::BlockType(240)},
        {mcpp::Coordinate(241, 20, 0), mcpp::BlockType(241)},
        {mcpp::Coordinate(242, 20, 0), mcpp::BlockType(242)},
        {mcpp::Coordinate(243, 20, 0), mcpp::BlockType(243)},
        {mcpp::Coordinate(244, 20, 0), mcpp::BlockType(244)},
        {mcpp::Coordinate(245, 20, 0), mcpp::BlockType(245)},
        {mcpp::Coordinate(246, 20, 0), mcpp::BlockType(246)},
        {mcpp::Coordinate(247, 20, 0), mcpp::BlockType(247)},
        {mcpp::Coordinate(248, 20, 0), mcpp::BlockType(248)},
        {mcpp::Coordinate(249, 20, 0), mcpp::BlockType(249)},
        {mcpp::Coordinate(250, 20, 0), mcpp::BlockType(250)},
        {mcpp::Coordinate(251, 20, 0), mcpp::BlockType(251)},
        {mcpp::Coordinate(251, 20, 1), mcpp::BlockType(251, 1)},
        {mcpp::Coordinate(251, 20, 2), mcpp::BlockType(251, 2)},
        {mcpp::Coordinate(251, 20, 3), mcpp::BlockType(251, 3)},
        {mcpp::Coordinate(251, 20, 4), mcpp::BlockType(251, 4)},
        {mcpp::Coordinate(251, 20, 5), mcpp::BlockType(251, 5)},
        {mcpp::Coordinate(251, 20, 6), mcpp::BlockType(251, 6)},
        {mcpp::Coordinate(251, 20, 7), mcpp::BlockType(251, 7)},
        {mcpp::Coordinate(251, 20, 8), mcpp::BlockType(251, 8)},
        {mcpp::Coordinate(251, 20, 9), mcpp::BlockType(251, 9)},
        {mcpp::Coordinate(251, 20, 10), mcpp::BlockType(251, 10)},
        {mcpp::Coordinate(251, 20, 11), mcpp::BlockType(251, 11)},
        {mcpp::Coordinate(251, 20, 12), mcpp::BlockType(251, 12)},
        {mcpp::Coordinate(251, 20, 13), mcpp::BlockType(251, 13)},
        {mcpp::Coordinate(251, 20, 14), mcpp::BlockType(251, 14)},
        {mcpp::Coordinate(251, 20, 15), mcpp::BlockType(251, 15)},
        {mcpp::Coordinate(252, 20, 0), mcpp::BlockType(252)},
        {mcpp::Coordinate(252, 20, 1), mcpp::BlockType(252, 1)},
        {mcpp::Coordinate(252, 20, 2), mcpp::BlockType(252, 2)},
        {mcpp::Coordinate(252, 20, 3), mcpp::BlockType(252, 3)},
        {mcpp::Coordinate(252, 20, 4), mcpp::BlockType(252, 4)},
        {mcpp::Coordinate(252, 20, 5), mcpp::BlockType(252, 5)},
        {mcpp::Coordinate(252, 20, 6), mcpp::BlockType(252, 6)},
        {mcpp::Coordinate(252, 20, 7), mcpp::BlockType(252, 7)},
        {mcpp::Coordinate(252, 20, 8), mcpp::BlockType(252, 8)},
        {mcpp::Coordinate(252, 20, 9), mcpp::BlockType(252, 9)},
        {mcpp::Coordinate(252, 20, 10), mcpp::BlockType(252, 10)},
        {mcpp::Coordinate(252, 20, 11), mcpp::BlockType(252, 11)},
        {mcpp::Coordinate(252, 20, 12), mcpp::BlockType(252, 12)},
        {mcpp::Coordinate(252, 20, 13), mcpp::BlockType(252, 13)},
        {mcpp::Coordinate(252, 20, 14), mcpp::BlockType(252, 14)},
        {mcpp::Coordinate(252, 20, 15), mcpp::BlockType(252, 15)},
        {mcpp::Coordinate(255, 20, 0), mcpp::BlockType(255)},
    };
}

} // namespace mcppv

#endif // __MCPPV_TYPES__