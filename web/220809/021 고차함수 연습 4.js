let bucketLists = [
    { id:3, text:'여행가기', done: false },
    { id:2, text:'치킨 먹기', done: true },
    { id:1, text:'코딩 하기', done: false },
];

function removeList(id){
    const newArr = bucketLists.filter(e=>{
        if(e.id != id)
        {
            return e
        }
    })
    console.log(newArr)
}

removeList(2);