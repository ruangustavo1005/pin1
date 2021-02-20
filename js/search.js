function onLoad() {
    debugger;
    document.getElementById('marca').style.display = 'block';
    document.getElementById('modelo').style.display = 'none';
}

function alterOption() {
    debugger;
    var oSelect   = document.getElementById('option'),
        sSelected = oSelect.options[oSelect.selectedIndex].value;
    
    if(sSelected === 'marca') {
        document.getElementById('marca').style.display = 'block';
        document.getElementById('modelo').style.display = 'none';
    } else {
        document.getElementById('modelo').style.display = 'block';
        document.getElementById('marca').style.display = 'none';
    }

}

//window.addEventListener('load', onLoad);