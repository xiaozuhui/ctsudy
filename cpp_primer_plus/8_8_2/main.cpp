#include <iostream>

struct CardyBar
{
    char * brand;
    double weight;
    int heat;
};

void CreateCardyBar(CardyBar & candt_bar, 
                  char * brand = "MM", 
                  double weight=2.85, 
                  int heat=350) 
{
    candt_bar.brand = brand;
    candt_bar.heat = heat;
    candt_bar.weight = weight;
}

void PrintCardyBar(const CardyBar & candt_bar) {
    std::cout << "Brand:\t" << candt_bar.brand << std::endl;
    std::cout << "Heat:\t" << candt_bar.heat << std::endl;
    std::cout << "Weight:\t" << candt_bar.weight << std::endl;
}

int main() {
    CardyBar cardybar;
    CreateCardyBar(cardybar);
    PrintCardyBar(cardybar);
    return 0;
}

