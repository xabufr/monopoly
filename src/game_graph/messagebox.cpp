#include "messagebox.h"
#include "../graphics/graphicalengine.h"

MessageBox::MessageBox(const std::string& title, const std::string& description)
{
    m_engine = GraphicalEngine::GetInstance();
    m_window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
    m_window->SetWindowTitle(title);
    m_window->SetClosable(true);

    GuiTextItem *item = new GuiTextItem;
    item->SetText(description);
    m_window->GetContener()->AjouterItem(item, 0, 0);
    m_window->CalculerTaille();
}
