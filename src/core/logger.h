#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <sstream>
#include "exception.h"

class Logger
{
    public:
        static const char endl;

        /** \brief Écrit la ligne donnée dans le logger courant
         *
         * \param ligne chaîne à écrire: le retour à la ligne n'est pas automatique
         */
        static void Out(std::string ligne);
        /** \brief Écrit la ligne donnée dans le logger courant, formatée façon C
         *
         * \param ligne chaîne à écrire: le retour à la ligne n'est pas automatique
         * \param ... paramètres supplémentaires
         */
        static void Out(const char* ligne, ...);
        /** \brief Écrit la ligne donnée dans le logger courant, formatée façon C
         *
         * \return Retourne le logger courant
         */
        static Logger& Log();
        /** \brief Ajoute des données au logger façon C++, i.e std::cout
         * \return Retourne le logger pour permettre le style C++
         */
        template<typename T>
        Logger& operator <<(const T& mes);
        /** \brief Ajoute des données au logger façon C++, i.e std::cout, version char[]
         * \return Retourne le logger pour permettre le style C++
         */
        Logger& operator <<(const char *mes);

        /** \brief Change le logger utilisé. L'ancien logger est automatiquement détruit.
         * \param log Nouveau logger
         */
        static void SetLogger(Logger *log);

        virtual ~Logger();

    protected:

    private:
        virtual void Write(const std::string &ligne) = 0;
        static Logger *m_logger;
        static void Destroy();
};
template <typename T>
Logger& Logger::operator <<(const T& message)
{
    Assert(m_logger!=NULL);

    std::ostringstream String;
    String << message;
    m_logger->Write(String.str());
    return Log();
}
#endif // LOGGER_H
