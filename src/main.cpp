#include "core/consolelogger.h"
#include "core/logger.h"
#include "graphics/graphicalengine.h" 
#include "graphics/gui/guicontener.h"
#include "graphics/gui/guibuttonitem.h"

int main()
{
	Logger::SetLogger(new ConsoleLogger());
	GraphicalEngine *engine = GraphicalEngine::GetInstance();
	engine->CreateRenderWindow(sf::VideoMode(800, 600, 32), "Monopoly");
	GuiManager *gui = engine->GetGuiManager();
	GuiContener *contener = gui->GetRootNode()->AddContener();
	GuiButtonItem *bQuitter = new GuiButtonItem;
	GuiButtonItem *bJouer = new GuiButtonItem;
	bQuitter->SetText("Quitter");
	bJouer->SetText("Jouer");
	contener->AjouterItem(bJouer, 0, 0);
	contener->AjouterItem(bQuitter, 0, 1);
	while(engine->GetRenderWindow()->isOpen())
	{
		sf::Event event;
		while(engine->GetRenderWindow()->pollEvent(event))
		{
			engine->GetGuiManager()->HandleEvent(event);
			if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Escape)
				engine->GetRenderWindow()->close();
		}
		engine->DrawScene();
	}
	return 0;
}
