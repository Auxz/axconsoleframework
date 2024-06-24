#ifndef MENU_h
#define MENU_h
#include <Windows.h>
#include <iostream>
#include <vector>

class Option
{
  public:
    int m_id;
    int m_row;
    std::string m_name;
    std::string m_description;
    bool m_showDesc;
    bool m_showId;

  private:
    bool m_selected;

  public:
    Option(const int a_id, std::string a_name, const std::string a_description, const bool a_showDesc,
           bool const a_showId);
    ~Option();
    bool isSelected();
    void updateSelected(const bool a_selected);

    void displayInformation();
};
class BaseMenu
{
  protected:
    std::string m_name;
    std::vector<Option *> m_options;
    bool isActive;
    BaseMenu(const std::string a_name);
    BaseMenu(const std::string a_name,
             const std::vector<Option *>
                 a_options); // Overloaded constructor to accept a pointer to a vector of Option object pointers
    virtual void display();

  public:
    void selectOption(int a_row);
    Option *getInput();
};
struct MenuHandler
{
  private:
    BaseMenu *m_activeMenu;

  public:
    MenuHandler();

    void setActiveMenu(BaseMenu *a_menu);
    BaseMenu *getActiveMenu();
};
class OptionsMenu : BaseMenu
{
  private:
    MenuHandler *m_menuHandler;

  public:
    OptionsMenu(const std::string a_name);

    OptionsMenu(const std::string a_name, const std::vector<Option *> a_options);
    virtual void display(bool displayMenuName = false);
    void addOption(Option *option);
    Option addOption(const int a_id, const std::string a_name, const std::string a_desc, const bool a_showDesc = false,
                     const bool a_showId = false);
};

void SendToInputHandler(char *inputBuffer[8], HANDLE *inputHandle, HANDLE *outputHandle);
void WindowsConsole();

#endif