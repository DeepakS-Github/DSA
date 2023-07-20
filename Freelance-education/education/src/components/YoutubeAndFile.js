import Yt from './Yt'
import { Pdf } from './Pdf'
import { Link } from "react-router-dom";
import { useParams } from "react-router-dom";
function YoutubeAndFile() {

  const { course, className, subject, topic, name, video, pdf } = useParams();

   // For coloring purpose

   let checkCategory = () => {
    if (course === "cbse") {
      if (className === "Class10") {
        return `from-sky-700 to-blue-700`;
      } else if (className === "Class11") {
        return `from-indigo-500 to-indigo-400`;
      } else if (className === "Class12") {
        return `from-rose-400 to-rose-300`;
      }
    } else if (course === "neet") {
      if (className === "Class11") {
        return `from-slate-500 to-slate-400`;
      } else if (className === "Class12") {
        return `from-emerald-500 to-emerald-400`;
      }
    } else if (course === "jee") {
      if (className === "Class11") {
        return `from-teal-500 to-teal-400`;
      } else if (className === "Class12") {
        return `from-lime-500 to-lime-400`;
      } else if (className === "Advanced") {
        return `from-orange-500 to-orange-400`;
      }
    }
  };

 

  const categoryColor = checkCategory();


  return (
    <>
    <section>
        <div
          className={`container px-6 mx-auto  bg-gradient-to-r ${categoryColor} subpixel-antialiased`}
        >
          <section className="text-gray-800 background-radial-gradient ">
            <div className="px-6 py-12 md:px-12 text-center lg:text-left">
              <div className="container mx-auto">
                <div className="grid lg:grid-cols-2 gap-12 flex items-center">
                  <div className="mt-16 lg:mt-0">
                    <h1 className="text-4xl md:text-5xl whitespace-nowrap xl:text-6xl font-bold tracking-tight mb-8 text-white">
                      <span className="uppercase">{course}</span> - {className}
                      <sup
                        className={`${className === "Advanced" ? "hidden" : ""
                          }`}
                      >
                        th
                      </sup>{" "}
                      - {subject.replace(/-/g, " ")}
                    </h1>
                    <p className="text-lg text-slate-100">
                      Lorem ipsum dolor sit amet consectetur adipisicing elit.
                      Minima officia consequatur adipisci tenetur repudiandae
                      rerum quos.
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </section>
        </div>
      </section>


    <div className='my-20 w-11/12 mx-auto'>
      <div className={`mb-4 w-full bg-gradient-to-r ${categoryColor} text-center mt-0 text-3xl font-normal text-white py-2 my-auto rounded-full`} >
        <h1>{topic}: {name}</h1>
      </div>
      <div className='flex mx-auto'>
      <Yt videoName={video}/>
      <Pdf pdfName={pdf}/>
      </div>
    </div>
    </>

  )
}
export default YoutubeAndFile
