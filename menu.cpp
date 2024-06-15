#include <iostream>
#include <vector>
#include <windows.h>
#define NAVIGATION_UP "\x1b[A"
#define NAVIGATION_DOWN VK_DOWN
#define NAVIGATION_LEFT VK_LEFT
#define NAVIGATION_RIGHT VK_RIGHT
#define NAVIGATION_ENTER VK_RETURN
#define NAVIGATION_ESC VK_ESCAPE
#define NAVIGATION_BACKSPACE VK_BACK
#define ESC "\x1b"
define CSI "\x1b["


namespace ax {
    namespace menu {
    class Option {
        public:
        int m_id;
        std::string m_name;
        std::string m_description;
        bool m_showDesc;
        bool m_showId;
        Option(const int a_id, std::string a_name, const std::string a_description, const bool a_showDesc, bool const a_showId)  {
            m_id = a_id;
            m_name = a_name;
            m_description = a_description;
            m_showDesc = a_showDesc;
            m_showId = a_showId;
        }
        
    
    
        void displayInformation() {
            std::string optionString;
            if(m_showId == true) 
            {
                optionString += std::to_string(m_id) + ". ";
            }
            optionString += m_name + " : ";
            if(m_showDesc == true) 
            {
                optionString += m_description;
            }
            std::cout << optionString << std::endl;

    };
    };
    class BaseMenu {
        protected:
        std::string m_name;
        std::vector<Option*> m_options;
            BaseMenu(const std::string a_name) 
            {
            m_name = a_name;
            }
            BaseMenu(const std::string a_name, const std::vector<Option*> a_options) // Overloaded constructor to accept a pointer to a vector of Option object pointers
            { 
            m_name = a_name;
            m_options = a_options;
            }   
            virtual void display() {}
    };
    class OptionsMenu : BaseMenu {
        private:
        public:
        OptionsMenu(const std::string a_name) : BaseMenu(a_name) {}
        OptionsMenu(const std::string a_name, const std::vector<Option*> a_options) : BaseMenu(a_name, a_options) {} 
        virtual void display(bool displayMenuName) 
        {
            if (displayMenuName) 
            {
            std::cout << m_name << std::endl;
            }
            for(Option* option : m_options) 
            {
                std::cout << option->m_name << std::endl;
                option->displayInformation();
            }
        }
        void addOption(Option* option) 
        {
            

        }
        Option addOption(const int a_id, const std::string a_name, const std::string a_desc, const bool a_showDesc, const bool a_showId) 
        {
            Option newOption = Option(a_id, a_name, a_desc, a_showDesc, a_showId);
            m_options.push_back(&newOption);
            return newOption;
        }
    };

    };
    namespace userinput {
        /* void NavigateMenu(const char[] sequence, HANDLE* outputHandle) 
        {
            char writeSequence[8];
            /*if(sequence == NAVIGATION_UP) 
            {
                writeSequence = NAVIGATION_UP;
                

            } // Likely redundant code need to verify and test
        } */
        void SendToInputHandler(char[]* inputBuffer, const HANDLE* outputHandle) 
        {
            std::string contents = std::to_string(*inputBuffer);
            if(contents == NAVIGATION_UP || NAVIGATION_DOWN || NAVIGATION_LEFT || NAVIGATION_RIGHT || NAVIGATION_ENTER || NAVIGATION_BACKSPACE || NAVIGATION_ESC)
            {
                
                WriteConsole(&outputHandle, inputBuffer, sizeof(inputBuffer), NULL, NULL);
                //NavigateMenu(*inputBuffer)

            }
        }
        void WindowsConsole() 
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
            
            SetConsoleMode(hIn, ENABLE_VIRTUAL_TERMINAL_INPUT);
            SetConsoleMode(hOut, ENABLE_VIRTUAL_TERMINAL_PROCESSING;);

            char inputBuffer[8];
            DWORD numberOfChars = 8;
            DWORD readChars;

            while(true) 
            {
            ReadConsole(hIn, &inputBuffer, numberOfChars, &readChars, NULL);
            SendToInputHandler(&inputBuffer, &hOut)
            }

        }




        /* void NavigateMenu(WORD keyCode) 
        {
            switch(keyCode) 
            {
                case NAVIGATION_UP:

                break;
                case NAVIGATION_DOWN:
                break;
                case NAVIGATION_LEFT:
                break;
                case NAVIGATION_RIGHT:
                break;
                case NAVIGATION_ENTER:
                break;
                case NAVIGATION_ESC:
                break;
                case NAVIGATION_BACKSPACE:
                break;
                default:
                break;
            }
        }
        void SendToInputHandler(const KEY_EVENT_RECORD kbEvent) 
        {
            if(kbEvent.bKeyDown) 
            {
                if(kbEvent.wVirtualKeyCode == NAVIGATION_UP || NAVIGATION_DOWN || NAVIGATION_LEFT || NAVIGATION_RIGHT ||  NAVIGATION_ENTER || NAVIGATION_ESC || NAVIGATION_BACKSPACE) 
                {
                    NavigateMenu(kbEvent.wVirtualKeyCode);
                }
            }
        }
        void getInput() 
        {
        HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD inputBuffer[10] = {};
        DWORD numberOfEvents = 0;
        while(true) {
            if(PeekConsoleInput(consoleInputHandle, &recordArray, DWORD(256), &numberOfEvents)) 
            {
                if(numberOfEvents != 0) 
                {
                    switch(irInBuffer[0].EventType) 
                    {
                        case KEY_EVENT:
                        SendToInputHandler(irInBuffer[0].Event.KeyEvent)
                        break;
                    }
                }
                };
            } */
    };

};