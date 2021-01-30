<?
namespace Estrutura;

/**
 * Interface base para componentes
 * @author Ruan
 */
interface Componente {
    
    /**
     * Retorna o nome do componente (div, input, table)
     * @return string
     */
    public function getNome();
    
    /**
     * Define o nome do componente (div, input, table)
     * @param string $sNome
     * @return $this
     */
    public function setNome($sNome);
    
    /**
     * Retorna todos os componentes
     * @return Componente[]
     */
    public function getComponentes();
    
    /**
     * Define todos os componentes
     * @param Componente[] $aComponentes
     * @return $this
     */
    public function setComponentes(array $aComponentes);
    
    /**
     * Retorna um componente dos componentes filhos
     * @return Componente
     */
    public function getComponente($sNome);
    
    /**
     * Adiciona um componente ao componentes filhos
     * @param Componente $oComponente
     * @return $this
     */
    public function addComponente(Componente $oComponente);
    
    /**
     * Remove um componente dos componentes filhos
     * @param string $sNome
     * @return Componente Componente que foi removido
     */
    public function removeComponente($sNome);
    
    /**
     * Procura um componente entre todos os componentes filhos, netos, bisnetos, etc.
     * @return Componente
     */
    public function findComponente($sNome);
    
    /**
     * Monta o HTML da tag e retorna o texto da mesma
     * @param bool $bComFilhos Define se deve ser retornado o HTML dos filhos junto
     * @return string
     */
    public function getHtml($bComFilhos = true);
    
}