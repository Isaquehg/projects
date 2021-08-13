//Project using for loops
function counting(){
    let sta_txt = window.document.getElementById('spoint');//start point
    let end_txt = window.document.getElementById('epoint');//end point
    let steps_txt = window.document.getElementById('step');//step
    let res = window.document.getElementById('res');//counting result

    //filtering input
    if(sta.value.length == 0 || end.value.length == 0 || steps.value.length == 0){
        window.alert('Please, verify the input!');
    }
    else{
        res.innerHTML = 'Counting... ';
        let sta = Number(sta_txt);
        let end = Number(end_txt);
        let steps = Number(steps_txt);
        
        for(let i = sta; i <= end; i += steps){
            res.innerHTML += `${i} \u{1F601}`;
        }
    }
}