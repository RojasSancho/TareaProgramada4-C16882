#ifndef EXCEPCIONCARACTERNOESNUMERO_H
#define EXCEPCIONCARACTERNOESNUMERO_H

#include <exception>

class ExcepcionCaracterNoEsNumero : public std::exception
{
    public:
    ExcepcionCaracterNoEsNumero() noexcept = default;
    ~ExcepcionCaracterNoEsNumero() = default;

    virtual const char* what() const noexcept
    {
        return "No esta permitido utilizar caracteres que no sean numeros.";
    }
};

#endif // EXCEPCIONCARACTERNOESNUMERO_H
