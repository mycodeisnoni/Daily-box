for(let t = 0 ; t<5 ; t++){

    let star = '*'

    for(let i = 0 ; i < 5-t ; i++){
        star += '*'
    }
    for( let j = 0 ; j < t+1 ;j++){
        star += '*'
    }
    console.log(star)
}