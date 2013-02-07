#include "scenenodetextureitem.h"
#include "../../core/exception.h"
#include "../../core/logger.h"
SceneNodeTextureItem::SceneNodeTextureItem()
{
    m_idTexture = TextureManager::GetInstance()->Create();
    m_texture = TextureManager::GetInstance()->GetFromId(m_idTexture);
}

SceneNodeTextureItem::~SceneNodeTextureItem()
{
    TextureManager::GetInstance()->DeleteTextureFromId(m_idTexture);
}
void SceneNodeTextureItem::CreateTexture(const sf::Vector2i& taille)
{
    m_texture->create(taille.x, taille.y);
    m_spr.setTexture(*m_texture);
    m_img.create(taille.x, taille.y);
}

void SceneNodeTextureItem::CreateTexture(const sf::Image& img)
{
    Assert(m_texture->loadFromImage(img));
    m_img = img;
    m_spr.setTexture(*m_texture);
}
void SceneNodeTextureItem::Draw(sf::RenderWindow* app)
{
    if(!m_visible)
        return;
    sf::Vector2f PosCam(app->getView().getCenter()-(app->getView().getSize()/2.f));
    sf::FloatRect rect(PosCam.x, PosCam.y, app->getView().getSize().x, app->getView().getSize().y);
    if(rect.intersects(m_spr.getGlobalBounds()))
        app->draw(m_spr);
}

void SceneNodeTextureItem::PositionChanged()
{
    m_spr.setOrigin(-m_relative.position);
    m_spr.setPosition(m_parent.position);
}
void SceneNodeTextureItem::RotationChanged()
{
    m_spr.setRotation(m_parent.rotation+m_relative.rotation);
}
void SceneNodeTextureItem::ScaleChanged()
{
    m_spr.setScale(
                   m_parent.scale.x*m_relative.scale.x,
                   m_parent.scale.y*m_relative.scale.y
                   );
}
void SceneNodeTextureItem::UpdateTexture(sf::Uint8* data, unsigned int w, unsigned int h, unsigned int x, unsigned int y)
{
    m_texture->update(data,w,h,x,y);
    int nb = 0;
    unsigned int px, py;
    for(unsigned int i=0;i<w*h*4;i+=4)
    {
        py = nb/w;
        px = nb - py*w;
        m_img.setPixel(x+px,y+py, sf::Color(data[i], data[i+1], data[i+2], data[i+3]));
        ++nb;
    }
    //delete m_texture;
    //m_texture = new sf::Texture();
    //m_texture->LoadFromImage(m_img);
}
inline float DistanceCarre(const sf::Vector2f &p1, const sf::Vector2f &p2)
{
    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
}
void SceneNodeTextureItem::DrawCircle(float rayon, const sf::Color& col, const sf::Vector2f& position)
{
    const float carreRayon = rayon*rayon;
    sf::Vector2i tailleZone(rayon*2, rayon*2);
    sf::Vector2i positionHG(position.x-rayon, position.y-rayon);
    sf::Vector2i decallage(0,0);
    if(position.y+rayon<0)
        return;
    if(position.x+rayon<0)
        return;
    if(position.x-rayon>m_img.getSize().x)
        return;
    if(position.y-rayon>m_img.getSize().y)
        return;

    if(position.x+rayon>m_img.getSize().x)
    {
        tailleZone.x=m_img.getSize().x-position.x+rayon+1;
    }
    else if(position.x-rayon<0)
    {
        tailleZone.x=position.x+rayon;
        positionHG.x=0;
    }
    if(position.y+rayon>m_img.getSize().y)
    {
        tailleZone.y=m_img.getSize().y-position.y+rayon;
    }
    else if(position.y-rayon<0)
    {
        tailleZone.y=position.y+rayon;
        positionHG.y=0;
    }
    if(tailleZone.x==0||tailleZone.y==0) return;
    const int iterations = tailleZone.y*tailleZone.x*4; //w*h*4
    sf::Uint8 remplacement[iterations];
    sf::Vector2i ptsEnCours;
    for(int i=0, iteration=0;i<iterations;i+=4,++iteration)
    {
        //Relatif HG
        ptsEnCours.y=iteration/tailleZone.x;
        ptsEnCours.x=iteration-ptsEnCours.y*tailleZone.x;
        if(DistanceCarre(position, sf::Vector2f(ptsEnCours.x+positionHG.x, ptsEnCours.y+positionHG.y))<carreRayon)
        {
            remplacement[i]=col.r;
            remplacement[i+1]=col.g;
            remplacement[i+2]=col.b;
            remplacement[i+3]=col.a;
            m_img.setPixel(ptsEnCours.x+positionHG.x, ptsEnCours.y+positionHG.y, col);

        }
        else
        {
            sf::Color col2 = m_img.getPixel(ptsEnCours.x+positionHG.x, ptsEnCours.y+positionHG.y);
            remplacement[i]=col2.r;
            remplacement[i+1]=col2.g;
            remplacement[i+2]=col2.b;
            remplacement[i+3]=col2.a;
        }
    }
    m_texture->update(remplacement, tailleZone.x, tailleZone.y, positionHG.x, positionHG.y);
}
void SceneNodeTextureItem::DrawCircle(float a, const sf::Color& col,  float b, float c)
{
    DrawCircle(a, col,sf::Vector2f(b,c));
}
const sf::Image& SceneNodeTextureItem::GetImage()const
{
    return m_img;
}
sf::Vector2f SceneNodeTextureItem::GetSize() const
{
    return sf::Vector2f(m_spr.getGlobalBounds().width, m_spr.getGlobalBounds().height);
}
