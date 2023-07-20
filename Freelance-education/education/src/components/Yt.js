export default function Yt(props) {
  return (
    <div className="w-3/5">
      {/* <div className="box1"></div> */}
      <div className="w-full h-[500px]">
        <iframe
          title="education-video"
          src={`https://www.youtube-nocookie.com/embed/${props.videoName}`}
          // src={props.video}
          width={'100%'}
          height={'100%'}
        ></iframe>
        {/* <div className="box3"></div>
        <div className="box4"></div> */}
      </div>

      {/* <div className="box2"></div> */}
    </div>
  )
}
