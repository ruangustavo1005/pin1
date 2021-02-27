<?php

/**
 * Classe para métodos estáticos de datas
 *
 * @author Leonardo Alex Fusinato
 */
class DateUtil {
    
    /**
     * Retorna um array com os dias da semana atual (sem sábado e domingo)
     * 
     * @return Array
     */
    public static function getDiasSemana() {
        $today = time();
        $wday = date('w', $today);   
        $aDatas[] = date('d/m/Y', $today - ($wday - 1) * 86400);
        $aDatas[] = date('d/m/Y', $today - ($wday - 2) * 86400);
        $aDatas[] = date('d/m/Y', $today - ($wday - 3) * 86400);
        $aDatas[] = date('d/m/Y', $today - ($wday - 4) * 86400);
        $aDatas[] = date('d/m/Y', $today - ($wday - 5) * 86400);
        return $aDatas;
    }
    
}