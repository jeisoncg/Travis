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

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;

/**
 *
 * @author jeisoncg
 */
public class ExtractorVerbos {

    private ArrayList<String> document_html;
    private ArrayList<String> conjuganos_no_procesados;
    private ArrayList<String> conjuganos_procesados_tablas;
    private ArrayList<String> titulos_h4;
    
    private final String HEADER = "<div class=\"aa\">";
    private final String END = "</div>";
    
    private ArrayList<Integer> pos_HEADER;
    private ArrayList<Integer> pos_END;
    
    private ArrayList<Seccion> secciones;

    public ExtractorVerbos() {
        this.document_html = new ArrayList<>();
        this.pos_HEADER = new ArrayList<>();
        this.pos_END = new ArrayList<>();
        this.conjuganos_no_procesados = new ArrayList<>();
        this.conjuganos_procesados_tablas = new ArrayList<>();
        this.titulos_h4 = new ArrayList<>();
        this.secciones = new ArrayList<>();
    }

    public ArrayList<String> getDocument_html() {
        return document_html;
    }

    public void setDocument_html(ArrayList<String> document_html) {
        this.document_html = document_html;
    }

    public ArrayList<String> getConjuganos_no_procesados() {
        return conjuganos_no_procesados;
    }

    public void setConjuganos_no_procesados(ArrayList<String> conjuganos_no_procesados) {
        this.conjuganos_no_procesados = conjuganos_no_procesados;
    }

    public ArrayList<String> getConjuganos_procesados_tablas() {
        return conjuganos_procesados_tablas;
    }

    public void setConjuganos_procesados_tablas(ArrayList<String> conjuganos_procesados_tablas) {
        this.conjuganos_procesados_tablas = conjuganos_procesados_tablas;
    }

    public ArrayList<String> getTitulos_h4() {
        return titulos_h4;
    }

    public void setTitulos_h4(ArrayList<String> titulos_h4) {
        this.titulos_h4 = titulos_h4;
    }

    public ArrayList<Integer> getPos_HEADER() {
        return pos_HEADER;
    }

    public void setPos_HEADER(ArrayList<Integer> pos_HEADER) {
        this.pos_HEADER = pos_HEADER;
    }

    public ArrayList<Integer> getPos_END() {
        return pos_END;
    }

    public void setPos_END(ArrayList<Integer> pos_END) {
        this.pos_END = pos_END;
    }

    public ArrayList<Seccion> getSecciones() {
        return secciones;
    }

    public void setSecciones(ArrayList<Seccion> secciones) {
        this.secciones = secciones;
    }
    
    public void loadDocumentHtml(String ruta) {

        try {
            String sCurrentLine = "";
            BufferedReader br  = new BufferedReader(new FileReader(new File(ruta)));
            
            while ((sCurrentLine = br.readLine()) != null) {
                this.document_html.add(sCurrentLine);
                //System.out.print(sCurrentLine + "\n");
            }
            br.close();
            setPositions();
            
        } catch (Exception ex) {
            System.err.println("Error:" + ex.getMessage());
        } 
        
    }
    
    private void setPositions(){
        boolean flagHEADER = false; //Indicamos si hemos encontrado una cabezera
        for (int i = 0; i < this.document_html.size(); i++) {
            
            if ((this.document_html.get(i).contains(HEADER))&&(!flagHEADER)){
                this.pos_HEADER.add(i);
                flagHEADER = true;
            }
            
            if ((this.document_html.get(i).contains(END)) && (flagHEADER)){
                this.pos_END.add(i);
                flagHEADER = false;
                
            }
            
        }
        
        
        
        /*for (int i = 0; i < this.pos_HEADER.size(); i++) {
            System.err.print(this.pos_HEADER.get(i) + " - " + this.pos_END.get(i) + "\n");
            
        }*/
        cargarConjugadosNoProcesados();
    }
    
    private void cargarConjugadosNoProcesados(){
    
        for (int i = 0; i < this.pos_HEADER.size(); i++) {
            String temporal_acumulativa = "";
            for (int j = this.pos_HEADER.get(i); j < this.pos_END.get(i); j++) {
                    
                temporal_acumulativa += this.document_html.get(j);
                
            }
            
            this.conjuganos_no_procesados.add(temporal_acumulativa);
            
        }
        
        
        
        /*for (int i = 0; i < this.conjuganos_no_procesados.size(); i++) {
            
            System.err.println(i + " ::: " + this.conjuganos_no_procesados.get(i));
            
        }*/
         limpiarConjugadosNoProcesados();
    }
    
    private void limpiarConjugadosNoProcesados(){
        String cadena_temporal = "";
        for (int i = 0; i < this.conjuganos_no_procesados.size(); i++) {
            
            cadena_temporal = this.conjuganos_no_procesados.get(i);
            cadena_temporal = cadena_temporal.replace(" class='neoConj active'","");
            cadena_temporal = cadena_temporal.replace("<div class=\"aa\">","");
            cadena_temporal = cadena_temporal.replace(" scope='col' colspan=2","");
            cadena_temporal = cadena_temporal.replace("<span class='arrow'></span>","");
            cadena_temporal = cadena_temporal.replace(" scope='row'","");
            cadena_temporal = cadena_temporal.replace(" class='neoConj'","");
            cadena_temporal = cadena_temporal.replace("<span class='antiquated'>'","");
            cadena_temporal = cadena_temporal.replace("<span class='antiquated'>","");
            cadena_temporal = cadena_temporal.replace("</span>","");
            
            
            this.conjuganos_procesados_tablas.add(cadena_temporal);
            
            //System.out.println(i + " ::: " + cadena_temporal.indexOf(">") + " ::: " + cadena_temporal);
           
        }
         getH4();
    }
    
    private void getH4(){
       // System.err.println("SIZE" + this.conjuganos_procesados_tablas.size());
        for (int i = 0; i < this.conjuganos_procesados_tablas.size(); i++) {
            
            String h4 = "";
            for (int j = this.conjuganos_procesados_tablas.get(i).indexOf(">")+1; j < this.conjuganos_procesados_tablas.get(i).indexOf("</h4>"); j++) {
                
                h4 += this.conjuganos_procesados_tablas.get(i).toCharArray()[j];
                
            }
            
            this.titulos_h4.add(h4);
        }
        
        for (int i = 0; i < this.titulos_h4.size(); i++) {
            //System.err.println(this.titulos_h4.get(i) + " ::: " + this.conjuganos_procesados_tablas.get(i));
            this.secciones.add(new Seccion(this.titulos_h4.get(i),this.conjuganos_procesados_tablas.get(i)));
            
        }
        
        for (int i = 0; i < this.secciones.size(); i++) {
            
            this.secciones.get(i).separarTablas(this.secciones.get(i).getCadena());
            
        }
        
       
        
    }
    

}

