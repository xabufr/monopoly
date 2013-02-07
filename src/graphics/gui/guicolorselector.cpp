#include "guicolorselector.h"
#include "../graphicalengine.h"
#include "../../../core/conversion.h"
#include "../../../core/logger.h"

GuiColorSelector::GuiColorSelector(SceneManager* mng, SceneNode* parent): GuiContener(mng, parent)
{
    m_selectR = new GuiSliderNumberItem;
    m_selectG = new GuiSliderNumberItem;
    m_selectB = new GuiSliderNumberItem;

    m_selectR->SetRange(0, 255);
    m_selectG->SetRange(0, 255);
    m_selectB->SetRange(0, 255);

    m_selectR->SetValue(255);
    m_selectG->SetValue(255);
    m_selectB->SetValue(255);

    m_selectR->SetColor(sf::Color(255,0,0));
    m_selectG->SetColor(sf::Color(255,0,0));
    m_selectB->SetColor(sf::Color(255,0,0));

    m_selectR->SetFocusColor(sf::Color(0, 255, 0));
    m_selectG->SetFocusColor(sf::Color(0, 255, 0));
    m_selectB->SetFocusColor(sf::Color(0, 255, 0));

    m_textR = new GuiTextItem;
    m_textG = new GuiTextItem;
    m_textB = new GuiTextItem;
    m_levelR = new GuiTextItem;
    m_levelG = new GuiTextItem;
    m_levelB = new GuiTextItem;

    m_levelR->SetText("255");
    m_levelG->SetText("255");
    m_levelB->SetText("255");

    m_textR->SetText("Rouge");
    m_textG->SetText("Vert");
    m_textB->SetText("Bleu");


    m_affCouleur = new GuiRectangleItem;
    m_affCouleur->SetSize(100, 100);

    this->AjouterItem(m_textR, 0, 0);
    this->AjouterItem(m_textG, 0, 1);
    this->AjouterItem(m_textB, 0, 2);

    this->AjouterItem(m_selectR, 1, 0);
    this->AjouterItem(m_selectG, 1, 1);
    this->AjouterItem(m_selectB, 1, 2);

    this->AjouterItem(m_levelR, 2, 0);
    this->AjouterItem(m_levelG, 2, 1);
    this->AjouterItem(m_levelB, 2, 2);

    this->AjouterItem(m_affCouleur, 1, 3);

    m_selectR->SetData("this", this);
    m_selectG->SetData("this", this);
    m_selectB->SetData("this", this);

    m_selectR->SetCallBack("value_changed", CallbackCouleurChanged);
    m_selectG->SetCallBack("value_changed", CallbackCouleurChanged);
    m_selectB->SetCallBack("value_changed", CallbackCouleurChanged);

    Update();
}

GuiColorSelector::~GuiColorSelector()
{
}
void GuiColorSelector::CallbackCouleurChanged(GuiItem* item)
{
    ((GuiColorSelector*)item->GetData("this"))->Update();
}
void GuiColorSelector::Update()
{
    m_affCouleur->SetColor(sf::Color(m_selectR->GetValue(), m_selectG->GetValue(), m_selectB->GetValue()));
    m_levelR->SetText(int2string(m_selectR->GetValue()));
    m_levelG->SetText(int2string(m_selectG->GetValue()));
    m_levelB->SetText(int2string(m_selectB->GetValue()));
}
void GuiColorSelector::HandleEvent(const sf::Event& event)
{
    if(!m_visible) return;
    for(SceneNodeItem* i : m_childItems)
    {
        ((GuiItem*)(i))->HandleEvent(event);
    }
}

void GuiColorSelector::SetColor(const sf::Color& color)
{
    m_selectR->SetValue(color.r);
    m_selectG->SetValue(color.g);
    m_selectB->SetValue(color.b);
    Update();
}
const sf::Color& GuiColorSelector::GetColor() const
{
    return m_affCouleur->GetColor();
}
