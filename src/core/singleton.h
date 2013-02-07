#ifndef H_SINGLETON_H
#define H_SINGLETON_H

template <typename T>
class Singleton
{
    /// @todo Documenter
    protected:
        Singleton(){}
        ~Singleton(){}

    public:
        static T* GetInstance()
        {
            if(m_singleton==0)
                m_singleton=new T;
            return m_singleton;
        }
        static void Kill()
        {
            if(m_singleton==0)
                return;
            delete m_singleton;
            m_singleton=0;
        }

    private:
        static T* m_singleton;
};

#endif
