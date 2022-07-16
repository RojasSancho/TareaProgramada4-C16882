#ifndef EXCEPCIONDATOSVACIOS_H
#define EXCEPCIONDATOSVACIOS_H

#include <exception>

class ExcepcionDatosVacios : public std::exception
{
    public:
    ExcepcionDatosVacios() noexcept = default;
    ~ExcepcionDatosVacios() = default;

    virtual const char* what() const noexcept
    {
        return "No esta permitido no dar el dato.";
    }
};

#endif // EXCEPCIONDATOSVACIOS_H
