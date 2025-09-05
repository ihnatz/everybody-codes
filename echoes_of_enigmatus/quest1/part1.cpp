#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

constexpr std::array<std::string_view, 10> input{
    "A=5 B=8 C=6 X=2 Y=4 Z=5 M=26",
    "A=5 B=9 C=9 X=8 Y=8 Z=5 M=12",
    "A=6 B=3 C=5 X=9 Y=4 Z=6 M=14",
    "A=5 B=3 C=9 X=5 Y=5 Z=6 M=21",
    "A=4 B=9 C=5 X=4 Y=6 Z=6 M=23",
    "A=6 B=6 C=7 X=9 Y=4 Z=8 M=12",
    "A=6 B=7 C=6 X=2 Y=8 Z=8 M=12",
    "A=4 B=8 C=9 X=3 Y=9 Z=5 M=11",
    "A=2 B=6 C=7 X=3 Y=8 Z=5 M=24",
    "A=4 B=9 C=8 X=5 Y=4 Z=6 M=16",
};


long eni(int n, int exp, int mod) {
    std::string s = "";
    long rem = 1;
    for (int i = 0; i < exp; i++) {
        rem = rem * n % mod;
        s = std::to_string(rem) + s;
    }
    return std::stol(s);
}


long process(const std::string& input) {
    std::istringstream iss(input);
    std::string token;

   int a, b, c, x, y, z, m;

    while (iss >> token) {
        char key;
        int value;

        std::istringstream pairStream(token);
        pairStream >> key;
        pairStream.ignore();
        pairStream >> value;

        switch (key) {
            case 'A': a = value; break;
            case 'B': b = value; break;
            case 'C': c = value; break;
            case 'X': x = value; break;
            case 'Y': y = value; break;
            case 'Z': z = value; break;
            case 'M': m = value; break;
            default: std::cerr << "Unknown key: " << key << "\n";
        }
    }

    return eni(a, x, m) + eni(b, y, m) + eni(c, z, m);
}


int main() {
    long max = 0;
    for (const auto& line : input) {
        long val = process(std::string(line));
        if (val > max) {
            max = val;
        }
    }
    std::cout << max  << std::endl;
    return 0;
}
