#ifndef EXCEPCIONDATOMUYGRANDE_H
#define EXCEPCIONDATOMUYGRANDE_H

#include <exception>

class ExcepcionDatoMuyGrande : public std::exception
{
    public:
    ExcepcionDatoMuyGrande() noexcept = default;
    ~ExcepcionDatoMuyGrande() = default;

    virtual const char* what() const noexcept
    {
        return "El dato ingresado tiene mucha extension.";
    }
};

#endif // EXCEPCIONDATOMUYGRANDE_H
