#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>

#include "level.h"
#include "struct.h"

const struct Block LEVELBLOCKS[5][64]= {
{
{2,5,5}, {2,9,5}, {2,13,5}, {2,17,5}, {2,21,5}, {2,25,5}, {2,29,5}, {2,33,5},
{2,37,5}, {2,41,5}, {2,45,5}, {2,49,5}, {2,53,5}, {2,57,5}, {2,61,5}, {2,65,5},
{2,69,5}, {2,73,5}, {1,5,7}, {1,9,7}, {1,13,7}, {1,17,7}, {1,21,7}, {1,25,7},
{1,29,7}, {1,33,7}, {1,37,7}, {1,41,7}, {1,45,7}, {1,49,7}, {1,53,7}, {1,57,7},
{1,61,7}, {1,65,7}, {1,69,7}, {1,73,7}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}
},
{
{ 2,5,8}, {2,5,9}, {2,9,7}, { 2,9,10}, {2,13,6}, {1,13,8}, {1,13,9}, {2,13,11},
{2,17,5}, {1,17,8}, {1,17,9}, {2,17,12}, {2,21,5}, {1,21,8}, {1,21,9}, {2,21,12},
{2,25,6}, {1,25,8}, {1,25,9}, {2,25,11}, {2,29,7}, {2,29,10}, {2,33,8}, {2,33,9},
{ 2,37,8}, {2,37,9}, {2,41,7}, { 2,41,10}, {2,45,6}, {1,45,8}, {1,45,9}, {2,45,11},
{2,49,5}, {1,49,8}, {1,49,9}, {2,49,12}, {2,53,5}, {1,53,8}, {1,53,9}, {2,53,12},
{2,57,6}, {1,57,8}, {1,57,9}, {2,57,11}, {2,61,7}, {2,61,10}, {2,65,8}, {2,65,9},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}
},
{
{4,3,4}, {4,7,4}, {4,11,4}, {4,15,4}, {4,21,4}, {4,25,4}, {4,29,4}, {4,33,4},
{4,37,4}, {4,41,4}, {4,45,4}, {4,49,4}, {4,51,4}, {4,55,4}, {4,59,4}, {4,63,4},
{4,67,4}, {4,71,4}, {4,75,4}, {4,2,15}, {4,6,15}, {4,10,15}, {4,14,15}, {4,4,13},
{4,8,13}, {4,12,13}, {4,6,11}, {4,10,11}, {4,8,9}, {4,75,15}, {4,71,15}, {4,67,15},
{4,63,15}, {4,65,13}, {4,69,13}, {4,73,13}, {4,67,11}, {4,71,11}, {4,69,9}, {4,39,14},
{4,37,12}, {4,41,12}, {4,35,10}, {4,39,10}, {4,43,10}, {4,37,8}, {4,41,8}, {4,19,14},
{4,17,12}, {4,21,12}, {4,15,10}, {4,19,10}, {4,23,10}, {4,17,8}, {4,21,8}, {4,59,14},
{4,57,12}, {4,61,12}, {4,55,10}, {4,59,10}, {4,63,10}, {4,57,8}, {4,61,8}, {4,39,14},
},
{
{3,19,4}, {3,16,5}, {3,22,5}, {3,15,6}, {3,23,6}, {2,15,7}, {2,23,7}, {2,15,8},
{2,23,8}, {2,16,9}, {2,22,9}, {2,19,10}, {4,19,7}, {1,27,10}, {1,27,11}, {3,35,4},
{3,32,5}, {3,38,5}, {3,31,6}, {3,39,6}, {2,31,7}, {2,39,7}, {2,31,8}, {2,39,8},
{2,32,9}, {2,38,9}, {2,35,10}, {4,35,7}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
{-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0}, {-1,0,0},
},
{
{3,16,3},  {3,14,4}, {1,17,4}, {3,12,5}, {1,15,5}, {3,10,6}, {1,13,6}, {3,11,7},
{1,14,7}, {3,12,8}, {2,14,9}, {2,14,10}, {2,14,11}, {4,17,9}, {4,17,10}, {4,17,11},
{4,20,9}, {4,20,10}, {4,20,11}, {4,23,9}, {4,23,10}, {4,23,11}, {4,26,9}, {4,26,10},
{4,26,11}, {4,29,9}, {4,29,10}, {4,29,11},  {4,32,9}, {4,32,10}, {4,32,11}, {4,35,9},
{4,35,10}, {4,35,11}, {4,38,9}, {4,38,10}, {4,38,11},  {4,41,9}, {4,41,10}, {4,41,11},
{4,44,9}, {4,44,10}, {4,44,11}, {4,47,9}, {4,47,10}, {4,47,11}, {4,50,9}, {4,50,10},
{4,50,11}, {4,53,9}, {4,53,10}, {4,53,11}, {4,56,9}, {4,56,10},	{4,56,11}, {4,59,9},
{4,59,10}, {4,59,11}, {4,62,9}, {4,62,10}, {4,62,11}, {-1,0,0}, {-1,0,0},{-1,0,0},
},

};

