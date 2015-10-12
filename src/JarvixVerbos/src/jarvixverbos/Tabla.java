/*
 * Copyright (C) 2015 jeisoncg
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package jarvixverbos;

import java.util.ArrayList;

/**
 *
 * @author jeisoncg
 */
public class Tabla {
    
    private String titulo;
    private int numeroColumnas;
    private ArrayList <String> columnas;
    private String cadenaOriginal;
    private ArrayList <String> filasSinProcesar;
    private String seccion;

    public Tabla() {
        this.titulo = this.cadenaOriginal = "";
        this.numeroColumnas = -1;
        this.columnas = new ArrayList<>();
        this.filasSinProcesar = new ArrayList<>();
    }

    public Tabla(String cadenaOriginal, String seccion) {
        this.seccion = seccion;
        this.cadenaOriginal = cadenaOriginal;
        this.titulo = "";
        this.numeroColumnas = -1;
        this.columnas = new ArrayList<>();
        this.filasSinProcesar = new ArrayList<>();
        this.procesarFilasDeCadena(cadenaOriginal);
        procesarTitulo();
        this.procesarFilasConConjugaciones();
        this.print();
    }

    public Tabla(String titulo, int numeroColumnas, ArrayList<String> columnas, String cadenaOriginal) {
        this.titulo = titulo;
        this.numeroColumnas = numeroColumnas;
        this.columnas = columnas;
        this.cadenaOriginal = cadenaOriginal;
        this.filasSinProcesar = new ArrayList<>();
    }

    public ArrayList<String> getFilasSinProcesar() {
        return filasSinProcesar;
    }

    public void setFilasSinProcesar(ArrayList<String> filasSinProcesar) {
        this.filasSinProcesar = filasSinProcesar;
    }

    public String getSeccion() {
        return seccion;
    }

    public void setSeccion(String seccion) {
        this.seccion = seccion;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getNumeroColumnas() {
        return numeroColumnas;
    }

    public void setNumeroColumnas(int numeroColumnas) {
        this.numeroColumnas = numeroColumnas;
    }

    public ArrayList<String> getColumnas() {
        return columnas;
    }

    public void setColumnas(ArrayList<String> columnas) {
        this.columnas = columnas;
    }

    public String getCadenaOriginal() {
        return cadenaOriginal;
    }

    public void setCadenaOriginal(String cadenaOriginal) {
        this.cadenaOriginal = cadenaOriginal;
    }

    private void procesarFilasDeCadena(String cadena) {
        if (cadena.length() == 0) {
            return;
        }

        int posicionInicioTabla = cadena.indexOf("<tr>") + 4; // Para iniciar en la posicion del >
        int posicionFinalTabla = cadena.indexOf("</tr>");

        String cadena_extraccion = "";

        for (int i = posicionInicioTabla; i < posicionFinalTabla; i++) {
            cadena_extraccion += cadena.toCharArray()[i];
        }

        this.filasSinProcesar.add(cadena_extraccion);

        String cadenaRescursiva = "";

        for (int i = posicionFinalTabla + 5; i < cadena.length(); i++) {
            cadenaRescursiva += cadena.toCharArray()[i];

        }

        this.procesarFilasDeCadena(cadenaRescursiva);

    }

    private void procesarTitulo() {

        for (int i = 4; i < this.filasSinProcesar.get(0).length() - 5; i++) {
            this.titulo += this.filasSinProcesar.get(0).toCharArray()[i];

        }
        // System.out.println("Titulo: " + this.titulo);
    }

    private void procesarFilasConConjugaciones() {
        

        for (int j = 1; j < this.filasSinProcesar.size(); j++) {
            String tmp = "";
            String tmp2 = "";
            String cadena = this.filasSinProcesar.get(j);
            for (int i = 4; i < cadena.indexOf("</th>"); i++) {
                tmp += cadena.toCharArray()[i];

            }

            for (int i = cadena.indexOf("<td>") + 4; i < cadena.indexOf("</td>"); i++) {
                tmp2 += cadena.toCharArray()[i];

            }
            tmp = tmp.replace("(", "");
            tmp = tmp.replace(")", "");
            tmp = tmp.replace(".", "");
            tmp2 = tmp2.replace("<i>o</i>", "==");
            this.columnas.add(tmp + "-" + tmp2);
            
        }

    }

    public void print() {
        System.out.print("seccion:" + this.seccion + "\n");
        System.out.print("{\n   titulo:" + this.titulo + "\n   filas:\n");
        for (int i = 0; i < this.filasSinProcesar.size(); i++) {

            //System.out.print("          fila:" + this.filasSinProcesar.get(i) + ";\n");

        }
        for (int i = 0; i < this.columnas.size(); i++) {
            
            System.out.print("          columna:" + this.columnas.get(i) + ";\n");
            
        }
        System.out.print("}\n ");
    }
}
