
let handleError = function(err){
    console.log("Error: ", err);
};


let remoteContainer = document.getElementById("remote-container");


function addVideoStream(elementId){
   
    let streamDiv = document.createElement("div");
    
    streamDiv.id = elementId;
    
    streamDiv.style.transform = "rotateY(180deg)";
   
    remoteContainer.appendChild(streamDiv);
}


function removeVideoStream(elementId) {
    let remoteDiv = document.getElementById(elementId);
    if (remoteDiv) remoteDiv.parentNode.removeChild(remoteDiv);
}

let client = AgoraRTC.createClient({
    mode: 'rtc',
    codec: 'vp8',
});

client.init('1f712a40b27a481bba40c1da11b7105b');


client.join(null, 'any-channel', null, (uid)=>{
   
    let localStream = AgoraRTC.createStream({
        audio: true,
        video: true,
    });
   
    localStream.init(()=>{
      
        localStream.play('me');
       
        client.publish(localStream, handleError);
    }, handleError);
  }, handleError);

  
client.on('stream-added', function(evt){
    client.subscribe(evt.stream, handleError);
});

client.on('stream-subscribed', function(evt){
    let stream = evt.stream;
    let streamId = String(stream.getId());
    addVideoStream(streamId);
    stream.play(streamId);
});


client.on('stream-removed', function(evt){
    let stream = evt.stream;
    let streamId = String(stream.getId());
    stream.close();
    removeVideoStream(streamId);
});

client.on('peer-leave', function(evt){
    let stream = evt.stream;
    let streamId = String(stream.getId());
    stream.close();
    removeVideoStream(streamId);
});
