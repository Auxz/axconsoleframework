#include <iostream>
#include "menu.cpp"
int main() {
    

    ax::menu::OptionsMenu myMenu = ax::menu::OptionsMenu("[-Test Menu-]");
    myMenu.addOption(1, "Hi", "My Description!", true, true);
    myMenu.display(true);
    
}