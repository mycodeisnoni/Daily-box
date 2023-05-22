let bucketLists = [
    { id:3, text:'여행가기', done: false },
    { id:2, text:'치킨 먹기', done: true },
    { id:1, text:'코딩 하기', done: false },
];

```function render(){
    const id = bucketLists.map(e=> e.id)
    const text = bucketLists.map(e=> e.text)
    
    for(let i =0; i<3;i++){
        let html = '<li id="' + id[i] + '"><label><input type="checkbox">' + text[i] + '</input></label></li>'
        console.log(html);
    }
    return html;
}

render();
```

//<li id="e.id"><label><input type="checkbox">e.text</input></label></li>


```function render(){
    let html = '';

    const newid = bucketLists.reduce((acc,cur)=>{
        acc[cur] = bucketLists.id[cur] 
        return acc;
    },[])
    const newtext = bucketLists.reduce((acc,cur)=>{
        acc[cur] = bucketLists.text[cur] 
        return acc;
    },[])

    html.push( '<li id="' + newid + '"><label><input type="checkbox">' +  + '</input></label></li>')


    return html;
}
console.log(html);```



function render(){
    let html = bucketLists.reduce((acc,cur) =>{
        let html = "<li id=\"" + cur.id + "\"><label>\n<input type=\"checkbox\">" + cur.text + "</input></label></li>\n"
        acc+=html
        return acc

    },'')
    console.log(html)
}

render();