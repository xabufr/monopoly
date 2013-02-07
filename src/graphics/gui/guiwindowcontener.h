#ifndef GUIWINDOWCONTENER_H
#define GUIWINDOWCONTENER_H
#include "guicontener.h"
/// @todo Documenter
class GuiWindowContener: public GuiContener
{
    public:
        GuiWindowContener(SceneManager*, SceneNode*);
        virtual ~GuiWindowContener();
        virtual void AjouterItem(GuiElement*, int, int);
    protected:
    private:
};

#endif // GUIWINDOWCONTENER_H
