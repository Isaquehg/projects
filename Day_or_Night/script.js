function loading(){ 
    var msg = window.document.getElementById('msg');
    var img = window.document.getElementById('img');
    var date = new Date();
    var hour = date.getHours();
    var greet;

    msg.innerHTML = `It's ${hour} Hours`
    if(hour >= 6 && hour < 12){//Morning
        img.src = 'Morning.png';
        document.body.style.background = '#ebc034';
        greet = 'Good Morning!';
    }
    else if(hour >= 12 && hour < 16){//Afternoon
        img.src = 'Afternoon.png';
        document.body.style.background = '#5cdb18';
        greet = 'Good Afternoon!';
    }
    else if(hour >= 16 && hour < 19){//Evening
        img.src = 'Evening.png';
        document.body.style.background = '#fcb314';
        greet = 'Good Evening!';
    }
    else{//Night
        img.src = 'Night.png';
        document.body.style.background = '#15274a';
        greet = 'Good Night!';
    }
    Greetings.innerHTML = greet;
}