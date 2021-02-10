<?php

/**
 * Persistência do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaVeiculo extends Persistencia {
    
    /**
     * Retorna todos os veículos disponíveis em estoque
     */
    public function getAllVeiculosDisponiveis() {
        $sSql = "
           SELECT *
             FROM tbveiculo
             LEFT JOIN tbmodelo 
               ON tbmodelo.modcodigo = tbveiculo.modcodigo
             LEFT JOIN tbmarca 
               ON tbmarca.marcodigo = tbmodelo.marcodigo
            WHERE tbveiculo.veisituacao = 1
        ";
        $aVeiculos = [];
        $oSql = $this->Query->query($sSql);
        foreach ($oSql->fetchAll(PDO::FETCH_OBJ) as $oObject) {
            $oVeiculo = new Veiculo();
            $oVeiculo->setPlaca($oObject->veiplaca);
            $oVeiculo->getModelo()->setCodigo($oObject->modcodigo);
            $oVeiculo->getModelo()->setNome($oObject->modnome);
            $oVeiculo->getModelo()->getMarca()->setCodigo($oObject->marcodigo);
            $oVeiculo->getModelo()->getMarca()->setNome($oObject->marnome);
            $oVeiculo->setAnoFabricacao($oObject->veianofabricacao);
            $oVeiculo->setCor($oObject->veicor);
            $oVeiculo->setPreco($oObject->veipreco);
            $oVeiculo->setQuilometragem($oObject->veiquilometragem);
            $oVeiculo->setObservacao($oObject->veiobservacao);
            $oVeiculo->setSituacao($oObject->veisituacao);
            $aVeiculos[] = $oVeiculo;
        }
        return $aVeiculos;
    }
    
    /**
     * Busca e seta todas as imagens do veículo passado por parâmetro
     * 
     * @param Veiculo $oVeiculo
     */
    public function getAllImagensFromVeiculo($oVeiculo) {
        $sSql = "
           SELECT veiplaca, ftvcodigo, encode(tbfotoveiculo.ftvconteudo, 'base64') as foto 
             FROM tbfotoveiculo
            WHERE veiplaca = :placa
        ";
        $oSql = $this->Query->prepare($sSql);
        $oSql->bindValue(':placa', $oVeiculo->getPlaca());
        $oSql->execute();
        foreach ($oSql->fetchAll(PDO::FETCH_OBJ) as $oObject) {
            $oVeiculo->newImagem($oObject->ftvcodigo, $oObject->foto);
        }
    }
    
}