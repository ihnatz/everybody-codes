#include <algorithm>

#include <array>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

constexpr std::array<std::string_view, 20> input{
    "ADD id=1 left=[247,G] right=[248,B]",
    "ADD id=2 left=[264,Z] right=[202,Y]",
    "ADD id=3 left=[283,H] right=[288,P]",
    "ADD id=4 left=[216,H] right=[278,G]",
    "ADD id=5 left=[227,Y] right=[230,M]",
    "ADD id=6 left=[255,M] right=[220,V]",
    "ADD id=7 left=[231,C] right=[240,L]",
    "ADD id=8 left=[286,T] right=[229,H]",
    "ADD id=9 left=[225,A] right=[291,Y]",
    "ADD id=10 left=[274,L] right=[206,Z]",
    "ADD id=11 left=[242,M] right=[241,P]",
    "ADD id=12 left=[239,V] right=[253,N]",
    "ADD id=13 left=[149,S] right=[110,P]",
    "ADD id=14 left=[290,M] right=[116,P]",
    "ADD id=15 left=[152,U] right=[148,M]",
    "ADD id=16 left=[117,Q] right=[281,L]",
    "ADD id=17 left=[250,K] right=[276,L]",
    "ADD id=18 left=[270,J] right=[219,L]",
    "ADD id=19 left=[134,M] right=[115,F]",
    "ADD id=20 left=[259,!] right=[163,M]",
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
  std::unique_ptr<Node> left_node;
  std::unique_ptr<Node> right_node;

  Node(int r, char l) : rank(r), letter(l) {}

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

  void assignSide(std::unique_ptr<Node> new_val) {
    if (new_val->rank > rank) {
      this->right_node = std::move(new_val);
    } else {
      this->left_node = std::move(new_val);
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

int main() {
  auto left_root = std::make_unique<Node>(0, 'A');
  auto right_root = std::make_unique<Node>(0, 'A');

  for (const auto [idx, line] : std::views::zip(std::views::iota(0), input)) {
    Note note = parse_note(std::string(line));
    if (idx == 0) {
      left_root->rank = note.left_rank;
      left_root->letter = note.left_val;
      right_root->rank = note.right_rank;
      right_root->letter = note.right_val;
      continue;
    }

    left_root->insert(std::make_unique<Node>(note.left_rank, note.left_val));
    right_root->insert(std::make_unique<Node>(note.right_rank, note.right_val));
  }

  std::vector<std::string> l_levels(10);
  std::vector<std::string> r_levels(10);

  traverse(left_root, 0, l_levels);
  traverse(right_root, 0, r_levels);
  auto longest_l = std::ranges::max_element(l_levels, {}, &std::string::size);
  auto longest_r = std::ranges::max_element(r_levels, {}, &std::string::size);

  std::cout << *longest_l << *longest_r << std::endl;

  return 0;
}
