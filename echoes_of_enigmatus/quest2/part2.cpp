#include <algorithm>

#include <array>
#include <deque>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

constexpr std::array<std::string_view, 201> input{
    "ADD id=1 left=[203,J] right=[986,R]",
    "ADD id=2 left=[399,R] right=[445,N]",
    "ADD id=3 left=[276,H] right=[157,X]",
    "ADD id=4 left=[547,L] right=[376,G]",
    "ADD id=5 left=[427,X] right=[355,N]",
    "SWAP 4",
    "ADD id=6 left=[188,N] right=[179,Y]",
    "ADD id=7 left=[335,Z] right=[105,V]",
    "ADD id=8 left=[190,G] right=[451,Z]",
    "ADD id=9 left=[435,N] right=[373,G]",
    "ADD id=10 left=[102,Y] right=[330,H]",
    "SWAP 2",
    "ADD id=11 left=[340,N] right=[379,X]",
    "ADD id=12 left=[353,T] right=[237,Z]",
    "ADD id=13 left=[281,X] right=[127,T]",
    "ADD id=14 left=[460,Z] right=[244,L]",
    "ADD id=15 left=[286,M] right=[461,V]",
    "SWAP 6",
    "ADD id=16 left=[404,P] right=[494,H]",
    "ADD id=17 left=[428,V] right=[302,T]",
    "ADD id=18 left=[121,T] right=[417,Y]",
    "ADD id=19 left=[491,L] right=[378,B]",
    "ADD id=20 left=[216,Z] right=[450,F]",
    "SWAP 1",
    "SWAP 10",
    "ADD id=21 left=[375,M] right=[287,F]",
    "ADD id=22 left=[294,F] right=[304,P]",
    "ADD id=23 left=[472,H] right=[328,X]",
    "ADD id=24 left=[489,B] right=[163,Z]",
    "ADD id=25 left=[135,B] right=[357,F]",
    "SWAP 2",
    "SWAP 24",
    "ADD id=26 left=[316,N] right=[385,S]",
    "ADD id=27 left=[406,R] right=[209,X]",
    "ADD id=28 left=[341,J] right=[473,N]",
    "ADD id=29 left=[364,F] right=[220,N]",
    "ADD id=30 left=[670,P] right=[752,R]",
    "SWAP 3",
    "SWAP 21",
    "SWAP 10",
    "ADD id=31 left=[577,F] right=[214,L]",
    "ADD id=32 left=[351,M] right=[356,N]",
    "ADD id=33 left=[573,V] right=[560,Z]",
    "ADD id=34 left=[588,T] right=[475,X]",
    "ADD id=35 left=[590,X] right=[258,R]",
    "SWAP 25",
    "SWAP 13",
    "SWAP 32",
    "ADD id=36 left=[485,J] right=[425,M]",
    "ADD id=37 left=[563,M] right=[609,W]",
    "ADD id=38 left=[496,L] right=[559,V]",
    "ADD id=39 left=[594,G] right=[678,H]",
    "ADD id=40 left=[198,V] right=[457,L]",
    "SWAP 15",
    "SWAP 25",
    "SWAP 13",
    "SWAP 30",
    "ADD id=41 left=[761,T] right=[700,Y]",
    "ADD id=42 left=[449,H] right=[740,J]",
    "ADD id=43 left=[688,Z] right=[694,X]",
    "ADD id=44 left=[571,S] right=[321,J]",
    "ADD id=45 left=[572,Q] right=[158,X]",
    "SWAP 39",
    "SWAP 20",
    "SWAP 31",
    "SWAP 15",
    "ADD id=46 left=[583,F] right=[762,W]",
    "ADD id=47 left=[777,S] right=[730,W]",
    "ADD id=48 left=[620,W] right=[444,H]",
    "ADD id=49 left=[471,G] right=[248,F]",
    "ADD id=50 left=[155,V] right=[159,S]",
    "SWAP 27",
    "SWAP 43",
    "SWAP 42",
    "SWAP 26",
    "SWAP 41",
    "ADD id=51 left=[476,H] right=[614,N]",
    "ADD id=52 left=[103,R] right=[719,T]",
    "ADD id=53 left=[655,M] right=[723,K]",
    "ADD id=54 left=[867,L] right=[595,R]",
    "ADD id=55 left=[854,H] right=[459,M]",
    "SWAP 14",
    "SWAP 33",
    "SWAP 27",
    "SWAP 25",
    "SWAP 53",
    "ADD id=56 left=[725,F] right=[447,R]",
    "ADD id=57 left=[565,R] right=[463,H]",
    "ADD id=58 left=[548,A] right=[361,T]",
    "ADD id=59 left=[692,X] right=[301,!]",
    "ADD id=60 left=[841,F] right=[773,Z]",
    "SWAP 25",
    "SWAP 53",
    "SWAP 38",
    "SWAP 36",
    "SWAP 59",
    "SWAP 33",
    "ADD id=61 left=[625,M] right=[633,Z]",
    "ADD id=62 left=[567,W] right=[847,C]",
    "ADD id=63 left=[217,M] right=[478,L]",
    "ADD id=64 left=[827,H] right=[542,R]",
    "ADD id=65 left=[848,V] right=[756,B]",
    "SWAP 62",
    "SWAP 36",
    "SWAP 58",
    "SWAP 59",
    "SWAP 64",
    "SWAP 17",
    "ADD id=66 left=[122,Y] right=[165,F]",
    "ADD id=67 left=[888,J] right=[297,T]",
    "ADD id=68 left=[381,B] right=[668,G]",
    "ADD id=69 left=[454,R] right=[840,W]",
    "ADD id=70 left=[570,P] right=[703,R]",
    "SWAP 58",
    "SWAP 69",
    "SWAP 52",
    "SWAP 32",
    "SWAP 60",
    "SWAP 9",
    "SWAP 38",
    "ADD id=71 left=[429,Z] right=[889,V]",
    "ADD id=72 left=[138,B] right=[793,G]",
    "ADD id=73 left=[782,Z] right=[690,S]",
    "ADD id=74 left=[887,X] right=[443,H]",
    "ADD id=75 left=[336,X] right=[185,G]",
    "SWAP 51",
    "SWAP 26",
    "SWAP 53",
    "SWAP 15",
    "SWAP 16",
    "SWAP 5",
    "SWAP 6",
    "ADD id=76 left=[770,H] right=[826,N]",
    "ADD id=77 left=[393,L] right=[104,P]",
    "ADD id=78 left=[664,Z] right=[837,T]",
    "ADD id=79 left=[581,P] right=[856,B]",
    "ADD id=80 left=[360,L] right=[749,B]",
    "SWAP 67",
    "SWAP 29",
    "SWAP 4",
    "SWAP 50",
    "SWAP 32",
    "SWAP 40",
    "SWAP 11",
    "SWAP 66",
    "ADD id=81 left=[115,P] right=[585,F]",
    "ADD id=82 left=[892,G] right=[796,W]",
    "ADD id=83 left=[835,Z] right=[278,M]",
    "ADD id=84 left=[918,W] right=[607,N]",
    "ADD id=85 left=[243,V] right=[284,J]",
    "SWAP 79",
    "SWAP 17",
    "SWAP 44",
    "SWAP 28",
    "SWAP 70",
    "SWAP 24",
    "SWAP 77",
    "SWAP 84",
    "ADD id=86 left=[916,V] right=[541,R]",
    "ADD id=87 left=[930,J] right=[628,Y]",
    "ADD id=88 left=[495,U] right=[846,W]",
    "ADD id=89 left=[734,V] right=[173,M]",
    "ADD id=90 left=[492,F] right=[345,V]",
    "SWAP 87",
    "SWAP 48",
    "SWAP 78",
    "SWAP 63",
    "SWAP 28",
    "SWAP 77",
    "SWAP 17",
    "SWAP 5",
    "SWAP 70",
    "ADD id=91 left=[553,P] right=[823,F]",
    "ADD id=92 left=[442,B] right=[685,W]",
    "ADD id=93 left=[386,N] right=[786,H]",
    "ADD id=94 left=[781,H] right=[579,X]",
    "ADD id=95 left=[501,H] right=[189,X]",
    "SWAP 32",
    "SWAP 59",
    "SWAP 10",
    "SWAP 66",
    "SWAP 12",
    "SWAP 5",
    "SWAP 74",
    "SWAP 7",
    "SWAP 48",
    "ADD id=96 left=[702,B] right=[970,W]",
    "ADD id=97 left=[145,F] right=[592,N]",
    "ADD id=98 left=[697,Y] right=[584,L]",
    "ADD id=99 left=[830,W] right=[876,T]",
    "ADD id=100 left=[536,Y] right=[794,T]",
    "SWAP 52",
    "SWAP 90",
    "SWAP 80",
    "SWAP 46",
    "SWAP 73",
    "SWAP 64",
    "SWAP 11",
    "SWAP 27",
    "SWAP 89",
    "SWAP 85",
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
  int rank;
  char letter;
  Node *left_node;
  Node *right_node;

  Node(int r, char l) : rank(r), letter(l) {}

  bool isLeaf() const { return left_node == nullptr && right_node == nullptr; }

  void insert(Node *new_val) {
    if (new_val->rank > rank) {
      if (right_node != nullptr) {
        right_node->insert(new_val);
      } else {
        right_node = new_val;
      }
    } else {
      if (left_node != nullptr) {
        left_node->insert(new_val);
      } else {
        left_node = new_val;
      }
    }
  }

  void assignSide(Node *new_val) {
    if (new_val->rank > rank) {
      this->right_node = new_val;
    } else {
      this->left_node = new_val;
    }
  }
};

void traverse(const Node *node, size_t level,
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

int main() {
  std::deque<std::unique_ptr<Node>> lq;
  std::deque<std::unique_ptr<Node>> rq;

  lq.push_back(std::make_unique<Node>(0, 'A'));
  rq.push_back(std::make_unique<Node>(0, 'A'));

  const auto &left_root = lq.front();
  const auto &right_root = rq.front();

  for (const auto [idx, line] : std::views::zip(std::views::iota(0), input)) {
    if (line.starts_with("SWAP")) {
      auto id = std::stoi(std::string(line).substr(5)) - 1;
      std::cout << id << std::endl;
      auto l_rank = lq[id].get()->rank;
      auto l_letter = lq[id].get()->letter;
      lq[id].get()->rank = rq[id].get()->rank;
      lq[id].get()->letter = rq[id].get()->letter;
      rq[id].get()->rank = l_rank;
      rq[id].get()->letter = l_letter;
      continue;
    }
    std::cout << line << std::endl;
    Note note = parse_note(std::string(line));
    if (idx == 0) {
      left_root->rank = note.left_rank;
      left_root->letter = note.left_val;
      right_root->rank = note.right_rank;
      right_root->letter = note.right_val;
      continue;
    }

    lq.push_back(std::make_unique<Node>(note.left_rank, note.left_val));
    rq.push_back(std::make_unique<Node>(note.right_rank, note.right_val));

    const auto &lv = lq.back();
    const auto &rv = rq.back();

    left_root->insert(lv.get());
    right_root->insert(rv.get());
  }

  std::vector<std::string> l_levels(50);
  std::vector<std::string> r_levels(50);

  traverse(left_root.get(), 0, l_levels);
  traverse(right_root.get(), 0, r_levels);
  auto longest_l = std::ranges::max_element(l_levels, {}, &std::string::size);
  auto longest_r = std::ranges::max_element(r_levels, {}, &std::string::size);

  std::cout << *longest_l << *longest_r << std::endl;

  return 0;
}
