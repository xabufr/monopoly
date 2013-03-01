#ifndef GUIWINDOWITEM_H
#define GUIWINDOWITEM_H

#include "guinode.h"
#include "guinode.h"
#include "../scenenodeshapeitem.h"
#include "guibuttonitem.h"
#include "guitextitem.h"
#include "guiwindowcontener.h"
#include <SFML/Graphics/Color.hpp>
/// @todo Documenter
class GuiWindowNode: public GuiNode
{
    public:
        GuiWindowNode(SceneManager*, SceneNode*);
        virtual ~GuiWindowNode();
        virtual void HandleEvent(const sf::Event&);
        virtual void HandleEventRecurse(const sf::Event&);

        void SetClosable(bool);
        bool IsClosable()const;
        bool IsClosed() const;
        static void CloseWindowCallBack(GuiItem*);

        void SetWindowTitle(const std::string&);
        void SetColorTitle(sf::Color);
        void SetCharacterSizeTitle(int);
        void SetColorShape(sf::Color);
        void SetColorContener(sf::Color);
        void SetColorOutlineShape(sf::Color);
        void SetColorOutlineContener(sf::Color);

        GuiWindowContener* GetContener() const;
        void CalculerTaille();
		GuiItem* CloseItem();
		void ResetContener();

    protected:
        SceneNodeShapeItem *m_windowShape, *m_contenerShape;
        GuiButtonItem *m_btnClose;
        GuiTextItem *m_windowTitle;
        bool m_moving, m_closable;
        float m_hauteurTitle;
        sf::Vector2f m_posClickMoving;
        GuiWindowContener *m_contener;

        void ClosableChanged();
        void CalculerCoord();
    private:
        bool m_closed;
};

#endif // GUIWINDOWITEM_H
