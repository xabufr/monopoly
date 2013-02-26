#include "messagebox.h"
#include "../graphics/graphicalengine.h"

MessageBox::MessageBox(const std::string& title, const std::string& description, bool confirm):m_payer(confirm)
{
    m_engine = GraphicalEngine::GetInstance();
    m_window = m_engine->GetGuiManager()->GetRootNode()->AddWindow();
    m_window->SetWindowTitle(title);
    m_window->SetClosable(true);

    GuiTextItem *item = new GuiTextItem;
    item->SetText(description);
    m_window->GetContener()->AjouterItem(item, 0, 0);
    m_window->CalculerTaille();

    if (m_payer)
    {
        GuiButtonItem *button = new GuiButtonItem;
        button->SetText("Payer");
        button->SetData("this", this);
        button->SetCallBack("clicked", MessageBox::payer);
        m_window->GetContener()->AjouterItem(button, 1, 1);
        m_window->CalculerTaille();

        button = new GuiButtonItem;
        button->SetText("Tirer");
        button->SetData("this", this);
        button->SetCallBack("clicked", MessageBox::tirer);
        m_window->GetContener()->AjouterItem(button, 1, 1);
        m_window->CalculerTaille();
    }
}

bool MessageBox::wantPayed() const
{
    return m_payer;
}

void MessageBox::payer(GuiItem* g)
{
    ((MessageBox*)g->GetData("this"))->m_payer = true;
}

void MessageBox::tirer(GuiItem* g)
{
    ((MessageBox*)g->GetData("this"))->m_payer = false;
}
