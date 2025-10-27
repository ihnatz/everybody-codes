#include <algorithm>

#include <array>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

constexpr std::array<std::string_view, 601> input{
    "ADD id=1 left=[510,G] right=[983,F]",
    "ADD id=2 left=[162,T] right=[286,P]",
    "ADD id=3 left=[177,F] right=[230,L]",
    "ADD id=4 left=[251,G] right=[243,M]",
    "ADD id=5 left=[222,H] right=[236,G]",
    "SWAP 1",
    "ADD id=6 left=[185,L] right=[227,P]",
    "ADD id=7 left=[161,F] right=[228,X]",
    "ADD id=8 left=[166,J] right=[241,S]",
    "ADD id=9 left=[324,S] right=[292,F]",
    "ADD id=10 left=[136,P] right=[118,J]",
    "SWAP 9",
    "ADD id=11 left=[271,G] right=[322,J]",
    "ADD id=12 left=[199,L] right=[321,G]",
    "ADD id=13 left=[305,Y] right=[114,J]",
    "ADD id=14 left=[412,H] right=[284,V]",
    "ADD id=15 left=[442,A] right=[237,K]",
    "SWAP 8",
    "ADD id=16 left=[214,N] right=[364,F]",
    "ADD id=17 left=[323,C] right=[255,Y]",
    "ADD id=18 left=[448,F] right=[370,B]",
    "ADD id=19 left=[443,F] right=[356,P]",
    "ADD id=20 left=[312,M] right=[178,W]",
    "SWAP 8",
    "SWAP 12",
    "ADD id=21 left=[342,H] right=[485,X]",
    "ADD id=22 left=[261,G] right=[538,P]",
    "ADD id=23 left=[479,Z] right=[327,R]",
    "ADD id=24 left=[234,J] right=[477,L]",
    "ADD id=25 left=[283,J] right=[150,R]",
    "SWAP 23",
    "SWAP 17",
    "ADD id=26 left=[354,R] right=[187,Y]",
    "ADD id=27 left=[302,J] right=[458,!]",
    "ADD id=28 left=[406,G] right=[505,F]",
    "ADD id=29 left=[210,M] right=[450,G]",
    "ADD id=30 left=[521,Y] right=[536,G]",
    "SWAP 6",
    "SWAP 4",
    "SWAP 16",
    "ADD id=31 left=[497,X] right=[253,F]",
    "ADD id=32 left=[455,X] right=[398,F]",
    "ADD id=33 left=[308,X] right=[552,Z]",
    "ADD id=34 left=[160,Y] right=[537,B]",
    "ADD id=35 left=[431,N] right=[144,F]",
    "SWAP 1",
    "SWAP 16",
    "SWAP 23",
    "ADD id=36 left=[394,W] right=[509,M]",
    "ADD id=37 left=[182,G] right=[429,Y]",
    "ADD id=38 left=[387,G] right=[457,N]",
    "ADD id=39 left=[311,V] right=[397,P]",
    "ADD id=40 left=[580,F] right=[677,S]",
    "SWAP 5",
    "SWAP 38",
    "SWAP 2",
    "SWAP 28",
    "ADD id=41 left=[184,B] right=[466,R]",
    "ADD id=42 left=[309,X] right=[623,H]",
    "ADD id=43 left=[636,Z] right=[730,R]",
    "ADD id=44 left=[660,J] right=[594,X]",
    "ADD id=45 left=[499,X] right=[422,N]",
    "SWAP 22",
    "SWAP 37",
    "SWAP 16",
    "SWAP 29",
    "ADD id=46 left=[670,B] right=[462,L]",
    "ADD id=47 left=[467,G] right=[697,T]",
    "ADD id=48 left=[667,X] right=[600,B]",
    "ADD id=49 left=[637,L] right=[559,S]",
    "ADD id=50 left=[608,N] right=[270,M]",
    "SWAP 8",
    "SWAP 12",
    "SWAP 42",
    "SWAP 36",
    "SWAP 16",
    "ADD id=51 left=[532,M] right=[690,Y]",
    "ADD id=52 left=[685,Y] right=[676,B]",
    "ADD id=53 left=[717,R] right=[578,L]",
    "ADD id=54 left=[334,V] right=[898,F]",
    "ADD id=55 left=[282,T] right=[926,M]",
    "SWAP 51",
    "SWAP 6",
    "SWAP 25",
    "SWAP 29",
    "SWAP 22",
    "ADD id=56 left=[616,B] right=[121,P]",
    "ADD id=57 left=[482,M] right=[472,P]",
    "ADD id=58 left=[250,G] right=[349,P]",
    "ADD id=59 left=[708,S] right=[593,B]",
    "ADD id=60 left=[671,G] right=[937,R]",
    "SWAP 1",
    "SWAP 50",
    "SWAP 39",
    "SWAP 30",
    "SWAP 10",
    "SWAP 15",
    "ADD id=61 left=[604,V] right=[645,X]",
    "ADD id=62 left=[822,W] right=[860,X]",
    "ADD id=63 left=[797,L] right=[383,G]",
    "ADD id=64 left=[626,R] right=[526,T]",
    "ADD id=65 left=[682,J] right=[490,Y]",
    "SWAP 6",
    "SWAP 35",
    "SWAP 52",
    "SWAP 9",
    "SWAP 49",
    "SWAP 61",
    "ADD id=66 left=[915,L] right=[834,Y]",
    "ADD id=67 left=[701,Z] right=[784,N]",
    "ADD id=68 left=[785,B] right=[936,H]",
    "ADD id=69 left=[615,Y] right=[699,P]",
    "ADD id=70 left=[825,J] right=[591,R]",
    "SWAP 66",
    "SWAP 6",
    "SWAP 31",
    "SWAP 21",
    "SWAP 58",
    "SWAP 24",
    "SWAP 54",
    "ADD id=71 left=[419,N] right=[646,W]",
    "ADD id=72 left=[372,Z] right=[231,P]",
    "ADD id=73 left=[911,R] right=[755,T]",
    "ADD id=74 left=[831,B] right=[576,Z]",
    "ADD id=75 left=[320,B] right=[357,S]",
    "SWAP 42",
    "SWAP 1",
    "SWAP 13",
    "SWAP 62",
    "SWAP 56",
    "SWAP 63",
    "SWAP 52",
    "ADD id=76 left=[115,H] right=[196,Z]",
    "ADD id=77 left=[461,J] right=[535,V]",
    "ADD id=78 left=[830,F] right=[260,N]",
    "ADD id=79 left=[565,H] right=[500,M]",
    "ADD id=80 left=[273,R] right=[405,B]",
    "SWAP 32",
    "SWAP 12",
    "SWAP 46",
    "SWAP 63",
    "SWAP 5",
    "SWAP 21",
    "SWAP 65",
    "SWAP 62",
    "ADD id=81 left=[795,V] right=[611,R]",
    "ADD id=82 left=[948,Y] right=[932,X]",
    "ADD id=83 left=[463,V] right=[814,H]",
    "ADD id=84 left=[112,F] right=[106,Z]",
    "ADD id=85 left=[881,W] right=[148,M]",
    "SWAP 63",
    "SWAP 65",
    "SWAP 11",
    "SWAP 69",
    "SWAP 7",
    "SWAP 22",
    "SWAP 36",
    "SWAP 46",
    "ADD id=86 left=[465,X] right=[899,J]",
    "ADD id=87 left=[474,Y] right=[922,P]",
    "ADD id=88 left=[434,G] right=[294,V]",
    "ADD id=89 left=[644,W] right=[548,H]",
    "ADD id=90 left=[514,S] right=[256,N]",
    "SWAP 80",
    "SWAP 59",
    "SWAP 22",
    "SWAP 79",
    "SWAP 50",
    "SWAP 28",
    "SWAP 75",
    "SWAP 72",
    "SWAP 30",
    "ADD id=91 left=[844,W] right=[930,Z]",
    "ADD id=92 left=[598,N] right=[408,B]",
    "ADD id=93 left=[722,F] right=[912,R]",
    "ADD id=94 left=[704,W] right=[727,V]",
    "ADD id=95 left=[942,R] right=[738,J]",
    "SWAP 85",
    "SWAP 69",
    "SWAP 84",
    "SWAP 54",
    "SWAP 32",
    "SWAP 81",
    "SWAP 41",
    "SWAP 18",
    "SWAP 12",
    "ADD id=96 left=[879,W] right=[732,Y]",
    "ADD id=97 left=[728,X] right=[436,T]",
    "ADD id=98 left=[661,X] right=[935,F]",
    "ADD id=99 left=[780,J] right=[675,N]",
    "ADD id=100 left=[262,X] right=[109,R]",
    "SWAP 32",
    "SWAP 20",
    "SWAP 33",
    "SWAP 91",
    "SWAP 30",
    "SWAP 59",
    "SWAP 66",
    "SWAP 75",
    "SWAP 17",
    "SWAP 80",
    "ADD id=101 left=[420,B] right=[172,N]",
    "ADD id=102 left=[318,X] right=[498,M]",
    "ADD id=103 left=[640,Y] right=[643,N]",
    "ADD id=104 left=[352,Y] right=[105,X]",
    "ADD id=105 left=[319,R] right=[778,H]",
    "SWAP 94",
    "SWAP 100",
    "SWAP 35",
    "SWAP 67",
    "SWAP 64",
    "SWAP 12",
    "SWAP 25",
    "SWAP 8",
    "SWAP 76",
    "SWAP 58",
    "ADD id=106 left=[122,X] right=[371,P]",
    "ADD id=107 left=[924,P] right=[585,M]",
    "ADD id=108 left=[584,U] right=[395,T]",
    "ADD id=109 left=[301,J] right=[496,B]",
    "ADD id=110 left=[343,H] right=[707,X]",
    "SWAP 21",
    "SWAP 75",
    "SWAP 17",
    "SWAP 45",
    "SWAP 67",
    "SWAP 12",
    "SWAP 15",
    "SWAP 56",
    "SWAP 101",
    "SWAP 42",
    "SWAP 102",
    "ADD id=111 left=[555,F] right=[914,X]",
    "ADD id=112 left=[252,J] right=[400,G]",
    "ADD id=113 left=[871,M] right=[541,R]",
    "ADD id=114 left=[517,Z] right=[550,N]",
    "ADD id=115 left=[192,G] right=[154,W]",
    "SWAP 105",
    "SWAP 42",
    "SWAP 79",
    "SWAP 22",
    "SWAP 93",
    "SWAP 3",
    "SWAP 59",
    "SWAP 15",
    "SWAP 17",
    "SWAP 74",
    "SWAP 21",
    "ADD id=116 left=[411,G] right=[929,Y]",
    "ADD id=117 left=[895,Y] right=[939,G]",
    "ADD id=118 left=[941,W] right=[159,B]",
    "ADD id=119 left=[328,T] right=[388,X]",
    "ADD id=120 left=[315,T] right=[862,F]",
    "SWAP 93",
    "SWAP 63",
    "SWAP 23",
    "SWAP 29",
    "SWAP 86",
    "SWAP 40",
    "SWAP 119",
    "SWAP 71",
    "SWAP 35",
    "SWAP 69",
    "SWAP 80",
    "SWAP 11",
    "ADD id=121 left=[128,P] right=[553,V]",
    "ADD id=122 left=[787,B] right=[494,G]",
    "ADD id=123 left=[973,B] right=[716,H]",
    "ADD id=124 left=[954,B] right=[155,Y]",
    "ADD id=125 left=[686,Y] right=[268,V]",
    "SWAP 117",
    "SWAP 84",
    "SWAP 114",
    "SWAP 18",
    "SWAP 23",
    "SWAP 24",
    "SWAP 40",
    "SWAP 64",
    "SWAP 67",
    "SWAP 73",
    "SWAP 8",
    "SWAP 89",
    "ADD id=126 left=[298,J] right=[801,G]",
    "ADD id=127 left=[280,G] right=[605,P]",
    "ADD id=128 left=[981,Z] right=[723,P]",
    "ADD id=129 left=[889,H] right=[151,R]",
    "ADD id=130 left=[393,W] right=[329,Y]",
    "SWAP 97",
    "SWAP 64",
    "SWAP 20",
    "SWAP 35",
    "SWAP 66",
    "SWAP 72",
    "SWAP 80",
    "SWAP 19",
    "SWAP 77",
    "SWAP 100",
    "SWAP 57",
    "SWAP 104",
    "SWAP 6",
    "ADD id=131 left=[714,X] right=[702,J]",
    "ADD id=132 left=[969,N] right=[703,B]",
    "ADD id=133 left=[856,Z] right=[952,T]",
    "ADD id=134 left=[179,H] right=[751,V]",
    "ADD id=135 left=[958,J] right=[782,Z]",
    "SWAP 19",
    "SWAP 45",
    "SWAP 76",
    "SWAP 72",
    "SWAP 117",
    "SWAP 3",
    "SWAP 100",
    "SWAP 35",
    "SWAP 84",
    "SWAP 36",
    "SWAP 12",
    "SWAP 92",
    "SWAP 14",
    "ADD id=136 left=[293,F] right=[641,W]",
    "ADD id=137 left=[254,G] right=[124,L]",
    "ADD id=138 left=[239,Y] right=[483,N]",
    "ADD id=139 left=[749,M] right=[654,P]",
    "ADD id=140 left=[528,Z] right=[625,V]",
    "SWAP 132",
    "SWAP 106",
    "SWAP 127",
    "SWAP 95",
    "SWAP 113",
    "SWAP 94",
    "SWAP 131",
    "SWAP 68",
    "SWAP 107",
    "SWAP 90",
    "SWAP 124",
    "SWAP 78",
    "SWAP 7",
    "SWAP 99",
    "ADD id=141 left=[464,Z] right=[827,L]",
    "ADD id=142 left=[211,Y] right=[108,J]",
    "ADD id=143 left=[876,V] right=[957,N]",
    "ADD id=144 left=[335,Q] right=[140,R]",
    "ADD id=145 left=[950,V] right=[195,W]",
    "SWAP 60",
    "SWAP 136",
    "SWAP 63",
    "SWAP 118",
    "SWAP 25",
    "SWAP 16",
    "SWAP 52",
    "SWAP 59",
    "SWAP 93",
    "SWAP 35",
    "SWAP 90",
    "SWAP 28",
    "SWAP 101",
    "SWAP 125",
    "ADD id=146 left=[984,G] right=[993,N]",
    "ADD id=147 left=[674,L] right=[858,Z]",
    "ADD id=148 left=[513,V] right=[300,Z]",
    "ADD id=149 left=[403,R] right=[147,W]",
    "ADD id=150 left=[439,Y] right=[113,F]",
    "SWAP 14",
    "SWAP 82",
    "SWAP 72",
    "SWAP 47",
    "SWAP 52",
    "SWAP 97",
    "SWAP 86",
    "SWAP 112",
    "SWAP 96",
    "SWAP 50",
    "SWAP 84",
    "SWAP 59",
    "SWAP 73",
    "SWAP 81",
    "SWAP 137",
    "ADD id=151 left=[101,S] right=[988,Y]",
    "ADD id=152 left=[247,Y] right=[891,P]",
    "ADD id=153 left=[401,J] right=[743,B]",
    "ADD id=154 left=[746,G] right=[866,R]",
    "ADD id=155 left=[469,B] right=[872,G]",
    "SWAP 62",
    "SWAP 89",
    "SWAP 145",
    "SWAP 52",
    "SWAP 33",
    "SWAP 104",
    "SWAP 82",
    "SWAP 88",
    "SWAP 16",
    "SWAP 99",
    "SWAP 13",
    "SWAP 73",
    "SWAP 147",
    "SWAP 22",
    "SWAP 7",
    "ADD id=156 left=[337,J] right=[350,M]",
    "ADD id=157 left=[206,V] right=[259,S]",
    "ADD id=158 left=[212,S] right=[945,W]",
    "ADD id=159 left=[444,M] right=[910,B]",
    "ADD id=160 left=[880,W] right=[129,N]",
    "SWAP 112",
    "SWAP 42",
    "SWAP 3",
    "SWAP 111",
    "SWAP 48",
    "SWAP 50",
    "SWAP 97",
    "SWAP 149",
    "SWAP 156",
    "SWAP 28",
    "SWAP 116",
    "SWAP 141",
    "SWAP 77",
    "SWAP 92",
    "SWAP 89",
    "SWAP 135",
    "ADD id=161 left=[960,J] right=[792,P]",
    "ADD id=162 left=[807,N] right=[215,B]",
    "ADD id=163 left=[662,T] right=[189,M]",
    "ADD id=164 left=[224,W] right=[471,G]",
    "ADD id=165 left=[835,M] right=[589,S]",
    "SWAP 13",
    "SWAP 2",
    "SWAP 156",
    "SWAP 50",
    "SWAP 24",
    "SWAP 126",
    "SWAP 99",
    "SWAP 101",
    "SWAP 111",
    "SWAP 140",
    "SWAP 48",
    "SWAP 34",
    "SWAP 125",
    "SWAP 56",
    "SWAP 91",
    "SWAP 18",
    "ADD id=166 left=[238,P] right=[456,F]",
    "ADD id=167 left=[111,X] right=[313,H]",
    "ADD id=168 left=[712,Y] right=[362,F]",
    "ADD id=169 left=[882,Z] right=[149,T]",
    "ADD id=170 left=[569,X] right=[816,Y]",
    "SWAP 162",
    "SWAP 52",
    "SWAP 136",
    "SWAP 140",
    "SWAP 114",
    "SWAP 24",
    "SWAP 154",
    "SWAP 119",
    "SWAP 26",
    "SWAP 58",
    "SWAP 110",
    "SWAP 121",
    "SWAP 18",
    "SWAP 8",
    "SWAP 142",
    "SWAP 48",
    "SWAP 73",
    "ADD id=171 left=[501,V] right=[407,T]",
    "ADD id=172 left=[849,H] right=[771,N]",
    "ADD id=173 left=[959,P] right=[165,S]",
    "ADD id=174 left=[602,M] right=[197,N]",
    "ADD id=175 left=[213,T] right=[595,V]",
    "SWAP 36",
    "SWAP 101",
    "SWAP 82",
    "SWAP 160",
    "SWAP 97",
    "SWAP 61",
    "SWAP 87",
    "SWAP 159",
    "SWAP 69",
    "SWAP 142",
    "SWAP 65",
    "SWAP 130",
    "SWAP 151",
    "SWAP 4",
    "SWAP 94",
    "SWAP 174",
    "SWAP 26",
    "ADD id=176 left=[781,M] right=[609,W]",
    "ADD id=177 left=[453,M] right=[647,S]",
    "ADD id=178 left=[606,N] right=[775,J]",
    "ADD id=179 left=[307,Z] right=[980,L]",
    "ADD id=180 left=[678,Y] right=[551,B]",
    "SWAP 44",
    "SWAP 161",
    "SWAP 10",
    "SWAP 26",
    "SWAP 61",
    "SWAP 156",
    "SWAP 110",
    "SWAP 46",
    "SWAP 63",
    "SWAP 22",
    "SWAP 112",
    "SWAP 117",
    "SWAP 36",
    "SWAP 170",
    "SWAP 9",
    "SWAP 6",
    "SWAP 14",
    "SWAP 16",
    "ADD id=181 left=[852,Z] right=[380,J]",
    "ADD id=182 left=[299,X] right=[985,L]",
    "ADD id=183 left=[454,M] right=[310,P]",
    "ADD id=184 left=[885,M] right=[141,R]",
    "ADD id=185 left=[833,T] right=[568,P]",
    "SWAP 32",
    "SWAP 148",
    "SWAP 108",
    "SWAP 141",
    "SWAP 164",
    "SWAP 22",
    "SWAP 42",
    "SWAP 97",
    "SWAP 66",
    "SWAP 86",
    "SWAP 132",
    "SWAP 156",
    "SWAP 50",
    "SWAP 64",
    "SWAP 49",
    "SWAP 130",
    "SWAP 155",
    "SWAP 75",
    "ADD id=186 left=[711,T] right=[735,W]",
    "ADD id=187 left=[863,L] right=[763,J]",
    "ADD id=188 left=[386,M] right=[340,V]",
    "ADD id=189 left=[720,P] right=[648,M]",
    "ADD id=190 left=[468,Y] right=[884,T]",
    "SWAP 10",
    "SWAP 67",
    "SWAP 122",
    "SWAP 41",
    "SWAP 89",
    "SWAP 160",
    "SWAP 138",
    "SWAP 97",
    "SWAP 24",
    "SWAP 109",
    "SWAP 188",
    "SWAP 82",
    "SWAP 115",
    "SWAP 187",
    "SWAP 79",
    "SWAP 54",
    "SWAP 96",
    "SWAP 70",
    "SWAP 166",
    "ADD id=191 left=[919,R] right=[875,T]",
    "ADD id=192 left=[366,Z] right=[724,N]",
    "ADD id=193 left=[977,L] right=[183,T]",
    "ADD id=194 left=[392,X] right=[788,J]",
    "ADD id=195 left=[599,Z] right=[396,R]",
    "SWAP 78",
    "SWAP 100",
    "SWAP 151",
    "SWAP 65",
    "SWAP 77",
    "SWAP 23",
    "SWAP 127",
    "SWAP 31",
    "SWAP 74",
    "SWAP 49",
    "SWAP 142",
    "SWAP 55",
    "SWAP 45",
    "SWAP 67",
    "SWAP 130",
    "SWAP 35",
    "SWAP 13",
    "SWAP 81",
    "SWAP 83",
    "ADD id=196 left=[240,L] right=[635,Z]",
    "ADD id=197 left=[556,M] right=[925,G]",
    "ADD id=198 left=[908,T] right=[544,P]",
    "ADD id=199 left=[562,G] right=[963,X]",
    "ADD id=200 left=[581,R] right=[316,W]",
    "SWAP 164",
    "SWAP 176",
    "SWAP 80",
    "SWAP 135",
    "SWAP 157",
    "SWAP 143",
    "SWAP 21",
    "SWAP 84",
    "SWAP 63",
    "SWAP 162",
    "SWAP 158",
    "SWAP 68",
    "SWAP 65",
    "SWAP 140",
    "SWAP 173",
    "SWAP 35",
    "SWAP 46",
    "SWAP 40",
    "SWAP 72",
    "SWAP 159",
};

struct Note {
  std::string op;
  int id;
  int left_rank;
  char left_val;
  int right_rank;
  char right_val;
};

Note parse_note(const std::string &input) {
  Note note;
  std::istringstream iss(input);
  std::string token;

  iss >> note.op;

  iss >> token;
  note.id = std::stoi(token.substr(token.find('=') + 1));

  iss >> token;
  size_t l_start = token.find('[');
  size_t comma_pos = token.find(',');
  note.left_rank =
      std::stoi(token.substr(l_start + 1, comma_pos - l_start - 1));
  note.left_val = token[comma_pos + 1];

  iss >> token;
  size_t r_start = token.find('[');
  comma_pos = token.find(',');
  note.right_rank =
      std::stoi(token.substr(r_start + 1, comma_pos - r_start - 1));
  note.right_val = token[comma_pos + 1];

  return note;
}

struct Node {
  int _id;
  int rank;
  char letter;
  std::unique_ptr<Node> left_node;
  std::unique_ptr<Node> right_node;

  Node(int i, int r, char l) : _id(i), rank(r), letter(l) {}

  bool isLeaf() const { return left_node == nullptr && right_node == nullptr; }

  void insert(std::unique_ptr<Node> new_val) {
    if (new_val->rank > rank) {
      if (right_node != nullptr) {
        right_node->insert(std::move(new_val));
      } else {
        right_node = std::move(new_val);
      }
    } else {
      if (left_node != nullptr) {
        left_node->insert(std::move(new_val));
      } else {
        left_node = std::move(new_val);
      }
    }
  }
};

void traverse(const std::unique_ptr<Node> &node, size_t level,
              std::vector<std::string> &levels) {
  levels[level] += node->letter;

  if (node->isLeaf())
    return;

  if (node->left_node != nullptr) {
    traverse(node->left_node, level + 1, levels);
  }
  if (node->right_node != nullptr) {
    traverse(node->right_node, level + 1, levels);
  }
  return;
}

void printTree(const std::unique_ptr<Node> &node, std::string prefix = "",
               bool isRoot = true) {
  if (!node) {
    std::cout << prefix << "└── (null)" << std::endl;
    return;
  }

  std::cout << prefix;
  if (!isRoot) {
    std::cout << "├── ";
  }
  std::cout << "ID: " << node->_id << ", Letter: " << node->letter
            << ", Rank: " << node->rank << std::endl;

  if (node->left_node || node->right_node) {
    if (node->left_node) {
      printTree(node->left_node, prefix + (isRoot ? "" : "│   "), false);
    }
    if (node->right_node) {
      printTree(node->right_node, prefix + (isRoot ? "" : "│   "), false);
    }
  }
}

std::unique_ptr<Node> *find(std::unique_ptr<Node> &node, int id,
                            const std::unique_ptr<Node> *skip = nullptr) {
  if (!node) {
    return nullptr;
  }

  if (node->_id == id && &node != skip) {
    return &node;
  }

  std::unique_ptr<Node> *lv = find(node->left_node, id, skip);
  if (lv != nullptr) {
    return lv;
  }

  std::unique_ptr<Node> *rv = find(node->right_node, id, skip);
  return rv;
}

int main() {
  auto left_root = std::make_unique<Node>(0, 0, 'A');
  auto right_root = std::make_unique<Node>(0, 0, 'A');

  for (const auto [idx, line] : std::views::zip(std::views::iota(0), input)) {
    if (line.starts_with("SWAP")) {
      auto id = std::stoi(std::string(line).substr(5));
      auto l_node = find(left_root, id);
      auto r_node = find(right_root, id);

      if (l_node && r_node) {
        std::swap((*l_node)->rank, (*r_node)->rank);
        std::swap((*l_node)->letter, (*r_node)->letter);
        std::swap((*l_node)->left_node, (*r_node)->left_node);
        std::swap((*l_node)->right_node, (*r_node)->right_node);
      } else if (l_node && !r_node) {
        auto l_node2 = find(left_root, id, l_node);

        if (!l_node2) {
          continue;
        }

        std::swap((*l_node)->rank, (*l_node2)->rank);
        std::swap((*l_node)->letter, (*l_node2)->letter);
        std::swap((*l_node)->left_node, (*l_node2)->left_node);
        std::swap((*l_node)->right_node, (*l_node2)->right_node);
      } else if (!l_node && r_node) {
        auto r_node2 = find(right_root, id, r_node);

        if (!r_node2) {
          continue;
        }

        std::swap((*r_node)->rank, (*r_node2)->rank);
        std::swap((*r_node)->letter, (*r_node2)->letter);
        std::swap((*r_node)->left_node, (*r_node2)->left_node);
        std::swap((*r_node)->right_node, (*r_node2)->right_node);
      }
      continue;
    }
    Note note = parse_note(std::string(line));
    if (idx == 0) {
      left_root->_id = note.id;
      left_root->rank = note.left_rank;
      left_root->letter = note.left_val;
      right_root->_id = note.id;
      right_root->rank = note.right_rank;
      right_root->letter = note.right_val;
      continue;
    }

    left_root->insert(
        std::make_unique<Node>(note.id, note.left_rank, note.left_val));
    right_root->insert(
        std::make_unique<Node>(note.id, note.right_rank, note.right_val));
  }

  std::vector<std::string> l_levels(50);
  std::vector<std::string> r_levels(50);

  traverse(left_root, 0, l_levels);
  traverse(right_root, 0, r_levels);

  auto longest_l = std::ranges::max_element(l_levels, {}, &std::string::size);
  auto longest_r = std::ranges::max_element(r_levels, {}, &std::string::size);

  std::cout << *longest_l << *longest_r << std::endl;

  return 0;
}
