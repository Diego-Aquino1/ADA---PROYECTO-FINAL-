#ifndef CURSO_H
#define CURSO_H

#include "horario.h"

class Curso{
private:
    int profesor;
    int semestre;
    string nombreCurso;
    string nombreLargoCurso;

    map<int, vector<pair<string, string>>> profesorAsignado;
    vector<string> tiposCursos;
    vector<string> gruposCursos;

public:
    Curso(string nombreCorto)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = "";
        this->semestre = -1;
        this->profesor = -1;
    }
    Curso(string nombreCorto, int idSemestre)
    {
        this->nombreCurso = nombreCorto;
        this->semestre = idSemestre;
        this->nombreLargoCurso = "";
        this->profesor = -1;
    }
    Curso(string nombreCorto, string nombreCompleto)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = nombreCompleto;
        this->semestre = -1;
        this->profesor = -1;
    }
    Curso(string nombreCorto, string nombreCompleto, int idSemestre)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = nombreCompleto;
        this->semestre = idSemestre;
        this->profesor = -1;
    }

    int asignaridProfesor(int idProfesor)
    {
        return this->profesor = idProfesor;
    }

    int asignaridSemestre(int idSemestre)
    {
        return this->semestre = idSemestre;
    }

    int buscarAsignacionProfesor(int idProfesor, string tipoCurso, string grupoCurso)
    {
        if (this->profesorAsignado.find(idProfesor) == this->profesorAsignado.end()) 
            return -1;
        for (int idx = 0; idx < this->profesorAsignado[idProfesor].size(); idx++){
            if (this->profesorAsignado[idProfesor][idx].first == tipoCurso && this->profesorAsignado[idProfesor][idx].second == grupoCurso)
                return idx;
        }
        return -1;
    }
  
    int encontrarTipoCurso(string tipoCurso)
    {
        for (int idx = 0; idx < this->tiposCursos.size(); idx++)
            if (this->tiposCursos[idx] == tipoCurso)
                return idx;
        return -1;
    }

    int encontrarGrupoCurso(string grupoCurso)
    {
        for(int idx = 0; idx < this->gruposCursos.size(); idx++)
            if (this->gruposCursos[idx] == grupoCurso)
                return idx;
        return -1;
    }

    friend class Horario;
};

#endif // CURSO_H
