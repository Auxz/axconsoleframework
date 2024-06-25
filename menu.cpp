#define NAVIGATION_UP "\x1b[A"
#define NAVIGATION_DOWN VK_DOWN
#define NAVIGATION_LEFT VK_LEFT
#define NAVIGATION_RIGHT VK_RIGHT
#define NAVIGATION_ENTER VK_RETURN
#define NAVIGATION_ESC VK_ESCAPE
#define NAVIGATION_BACKSPACE VK_BACK
#define ENTER "\n"
#define ESC "\x1b"
#define CSI "\x1b["
#include "menu.hpp"


// Options


Option::Option(const int a_id, std::string a_name, const std::string a_description, const bool a_showDesc,
               bool const a_showId)
{
    m_id = a_id;
    m_name = a_name;
    m_description = a_description;
    m_showDesc = a_showDesc;
    m_showId = a_showId;
    m_selected = false;
    m_row = 0;
}
Option::~Option()
{
}
bool Option::isSelected()
{
    return m_selected;
}
void Option::updateSelected(const bool a_selected)
{
    m_selected = a_selected;
}

void Option::displayInformation()
{
    std::string optionString;
    if (m_showId == true)
    {
        // optionString += std::to_string(m_id) + ". ";
    }
    optionString += m_name + " : ";
    if (m_showDesc == true)
    {
        optionString += m_description;
    }
    std::cout << optionString << std::endl;
}


// Menus


BaseMenu::BaseMenu(const std::string a_name)
{
    m_name = a_name;
    isActive = false;
}
BaseMenu::BaseMenu(const std::string a_name, const std::vector<Option *> a_options) // Overloaded constructor to accept a pointer to a vector of Option object pointers
{
    m_name = a_name;
    m_options = a_options;
    isActive = false;
}
BaseMenu::~BaseMenu() 
{

}
/*void BaseMenu::display()
{
} */

void BaseMenu::selectOption(int a_row)
{
    for (Option *option : m_options)
    {
        if (option->m_row == a_row)
        {
            option->updateSelected(true);
        }
    }
}
Option *BaseMenu::getInput()
{
    while (true)
    {
        for (Option *option : m_options)
        {
            if (option->isSelected())
            {
                return option;
            }
        }
    }
}

MenuHandler::MenuHandler()
{
}

void MenuHandler::setActiveMenu(void* a_menu)
{
    m_activeMenu = a_menu;
}
auto *MenuHandler::getActiveMenu()
{
    if(sizeof(m_activeMenu)
}

OptionsMenu::OptionsMenu(const std::string a_name) : BaseMenu(a_name)
{
    // m_menuHandler = a_handler;
}

OptionsMenu::OptionsMenu(const std::string a_name, const std::vector<Option *> a_options) : BaseMenu(a_name, a_options)
{
    // m_menuHandler = a_handler;
}
void OptionsMenu::display(bool displayMenuName)
{
    if (displayMenuName)
    {
        std::cout << m_name << std::endl;
    }
    for (Option *option : m_options)
    {
        std::cout << option->m_name << std::endl;
        option->displayInformation();
    }
    m_menuHandler->setActiveMenu(this);
}
void OptionsMenu::addOption(Option *option)
{
}
Option OptionsMenu::addOption(const int a_id, const std::string a_name, const std::string a_desc, const bool a_showDesc,
                              const bool a_showId)
{
    Option newOption = Option(a_id, a_name, a_desc, a_showDesc, a_showId);
    m_options.push_back(&newOption);
    return newOption;
}
// namespace menu

void SendToInputHandler(char *inputBuffer[8], HANDLE *inputHandle, HANDLE *outputHandle)
{

    if (strcmp(*inputBuffer, NAVIGATION_UP) == 0)
    {

        WriteConsole(&outputHandle, inputBuffer, sizeof(*inputBuffer), NULL, NULL);
    }
    else if (strcmp(*inputBuffer, ENTER) == 0)
    {

        WriteConsole(outputHandle, CSI "6n", sizeof(*inputBuffer), NULL, NULL);
        char pBuffer[6];
        DWORD numberOfCharsRead = 0;
        ReadConsole(inputHandle, &pBuffer, 6, &numberOfCharsRead, NULL);
    }
}
void WindowsConsole()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hIn, ENABLE_VIRTUAL_TERMINAL_INPUT);
    SetConsoleMode(hOut, ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    char inputBuffer[8];
    DWORD numberOfChars = 8;
    DWORD readChars;
    char *ptr = inputBuffer;

    while (true)
    {
        ReadConsole(hIn, &inputBuffer, numberOfChars, &readChars, NULL);
        std::cout << inputBuffer;
        SendToInputHandler(&ptr, &hIn, &hOut);
    }
}

// namespace ax
