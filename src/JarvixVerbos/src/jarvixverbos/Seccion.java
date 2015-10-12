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
public class Seccion {
    
    private String h4;
    private String cadena;
    private ArrayList <Tabla> tablas;

    public ArrayList<Tabla> getTablas() {
        return tablas;
    }

    public void setTablas(ArrayList<Tabla> tablas) {
        this.tablas = tablas;
    }

    public Seccion() {
        this.h4 = this.cadena = "";
        this.tablas = new ArrayList<>();
    }

    public Seccion(String h4, String cadena) {
        this.h4 = h4;
        this.cadena = cadena;
        this.tablas = new ArrayList<>();
        //this.print();
    }

    public String getH4() {
        return h4;
    }

    public void setH4(String h4) {
        this.h4 = h4;
    }

    public String getCadena() {
        return cadena;
    }

    public void setCadena(String cadena) {
        this.cadena = cadena;
    }
    
    public void print(){
        System.out.print("{\n   titulo:'" + h4 + "';\n   cadenaHTML:'" + this.cadena + "';\n");
        for (int i = 0; i < tablas.size() ; i++) {
            
            System.out.print("   cadenaTabla:" + i + ":" + this.tablas.get(i).getCadenaOriginal() + ";\n");
        }
        System.out.print("\n}\n");
    }
    
    public void separarTablas(String cadena){
    
        if (cadena.length() == 0){
            return;
        }
        int posicionInicioTabla = cadena.indexOf("<table>") + 7; // Para iniciar en la posicion del >
        int posicionFinalTabla = cadena.indexOf("</table>");
        
        String cadena_extraccion = "";
        
        for (int i = posicionInicioTabla; i < posicionFinalTabla; i++) {
            cadena_extraccion += cadena.toCharArray()[i];
        }
        
        this.tablas.add(new Tabla(cadena_extraccion,this.h4));
        
        String cadenaRescursiva = "";
        
        for (int i = posicionFinalTabla + 8; i < cadena.length(); i++) {
            cadenaRescursiva += cadena.toCharArray()[i];
            
        }
        
        //System.err.println("Cadena Recursiva:" + cadenaRescursiva);
        this.separarTablas(cadenaRescursiva);
    };
    
}
