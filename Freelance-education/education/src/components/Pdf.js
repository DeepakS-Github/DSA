export const Pdf = (props) => {
  return (
    <div className="mx-auto w-2/5">
      <iframe
        title="education pdf"
        src={`https://drive.google.com/file/d/${props.pdfName}/preview`}
        width={'100%'}
          height={'100%'}
        allow="autoplay"

      ></iframe>
    </div>
  )
}
