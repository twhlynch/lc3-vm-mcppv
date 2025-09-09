#ifndef __MCPPV_SIMULATION__
#define __MCPPV_SIMULATION__

#include <mcpp/mcpp.h>
#include <vector>
#include <string>

namespace mcppv {

struct Block {
    mcpp::Coordinate coordinate;
    mcpp::BlockType blockType;
};

class Simulation {

  private:
    mcpp::Coordinate _playerPosition;
    std::vector<Block> _blocks;

  public:
    Simulation();

    void postToChat(const std::string& message);

    mcpp::Coordinate getPlayerPosition();
    void setPlayerPosition(const mcpp::Coordinate& pos);

    mcpp::BlockType getBlock(const mcpp::Coordinate& loc);
    void setBlock(const mcpp::Coordinate& loc, const mcpp::BlockType& blockType);

    int getHeight(int x, int z);

    void render();
};

} // namespace mcppv

#endif // __MCPPV_SIMULATION__
