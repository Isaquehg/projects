//Project using FOR loops
function counting(){
    let sta_txt = window.document.getElementById('spoint');//start point
    let end_txt = window.document.getElementById('epoint');//end point
    let steps_txt = window.document.getElementById('step');//step
    let res = window.document.getElementById('res');//counting result

    //filtering input
    if(sta_txt.value.length == 0 || end_txt.value.length == 0 || steps_txt.value.length == 0){
        window.alert('Please, verify the input!');
    }
    else{
        res.innerHTML = 'Counting... <br>';
        //conveting values
        let sta = Number(sta_txt.value);
        let end = Number(end_txt.value);
        let steps = Number(steps_txt.value);
        
        if(sta < end){//ascending
            for(let i = sta; i <= end; i += steps){
                res.innerHTML += ` ${i} \u{1F449}`;
            }
        }
        else{ //Descending
            for(let i = sta; i >= end; i -= steps){
                res.innerHTML += ` ${i} \u{1F449}`;
            }
        }
        res.innerHTML += ' <br>END!';
    }
}