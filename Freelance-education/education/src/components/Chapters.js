import React, { useState } from "react";
import { useEffect } from "react";
import { Link } from "react-router-dom";
import firebase from "./Firebase";
import { useParams } from "react-router-dom";

function Chapters() {
  const { course, className, subject } = useParams();
  const [openAccordian, setOpenAccordian] = useState(1);



  // For chapter table purpose
  const FCourse = () => {
    if (course === "cbse") {
      return "Boards";
    } else if (course === "neet") {
      return "NEET";
    } else if (course === "jee") {
      return "JEE";
    }
  };

  const FCategory = () => {
    if (subject === "Organic-Chemistry") {
      return ["Organic"];
    }
    else if (subject === "Physical+Inorganic-Chemistry") {
      return ["Physical", "Inorganic"];
    }
    else if (subject === "Chemistry") {
      return ["Chemistry"];
    }
    else if (subject === "Physics") {
      return ["Physics"];
    }
    else if (subject === "Mathematics") {
      return ["Mathematics"];
    }
    else if (subject === "Biology") {
      return ["Biology"];
    }
    else if (subject === "Science") {
      return ["Science"];
    }
  };

  console.log(className);

  const FClass = () => {
    if (className === "Class11") {
      return "11";
    } else if (className === "Class12") {
      return "12";
    } else if (className === "Class10") {
      return "10";
    } else if (className === "Advanced") {
      return "Advanced";
    }
  };

  const ref = firebase.firestore().collection(FCourse());
  // console.log(ref);
  const [loader, setLoader] = useState(true);

  const [data, setData] = useState([]);

  function getData() {
    ref.onSnapshot((querySnapshot) => {
      const items = [];
      querySnapshot.forEach((doc) => {
        items.push(doc.data());
        // console.log(doc.data());
      });
      setData(items);
      setLoader(false);
    });
  }

  useEffect(() => {
    getData();
  }, []);

  let data2 = {};

  const items = data.flatMap((dev) => {
    data2 = dev;
  });

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

  let checkCategoryText = () => {
    if (course === "cbse") {
      if (className === "Class10") {
        return `text-sky-700`;
      } else if (className === "Class11") {
        return `text-indigo-500`;
      } else if (className === "Class12") {
        return `text-rose-500`;
      }
    } else if (course === "neet") {
      if (className === "Class11") {
        return `text-slate-500`;
      } else if (className === "Class12") {
        return `text-emerald-500`;
      }
    } else if (course === "jee") {
      if (className === "Class11") {
        return `text-teal-500`;
      } else if (className === "Class12") {
        return `text-lime-500`;
      } else if (className === "Advanced") {
        return `text-orange-500`;
      }
    }
  };

  const categoryColor = checkCategory();
  const categoryTextColor = checkCategoryText();

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

      <div className="my-12">
        <div className={`w-full text-2xl py-4 text-center font-medium`}>
          {FCategory()[0]} {(course === "neet" || course === "jee") ? "Chemistry" : ""}
        </div>
        <section className="bg-white w-11/12 mx-auto">
          <div className="border border-neutral-200 bg-white">
            <div>
              {Object.keys(data2).map((key) => {
                if (key === FClass()) {
                  return (
                    <div key={key}>
                      {/* <div>Key: {key}</div> */}
                      {Object.keys(data2[key]).map((category) => {
                        if (category === FCategory()[0]) {
                          return (
                            <div key={category}>
                              {Object.keys(data2[key][category]).map(
                                (chapterKey) => (
                                  <div key={chapterKey}>
                                    {console.log(chapterKey)}
                                    <h2>
                                      <button
                                        className="group relative flex w-full items-center rounded-t-[15px] border-0 bg-white py-4 px-5 text-left text-base text-neutral-800 transition hover:z-[2] focus:z-[3] focus:outline-none [&:not [&:not([data-te-collapse-collapsed])]:[box-shadow:inset_0_-1px_0_rgba(229,231,235)]"
                                        type="button"
                                        onClick={() => {
                                          openAccordian
                                            ? setOpenAccordian(0)
                                            : setOpenAccordian(1);
                                        }}
                                      >
                                        <i
                                          className={`fa-solid fa-pen mr-4 ${categoryTextColor}`}
                                        ></i>
                                        <span className="font-medium">
                                          {chapterKey}:{" "}
                                          {
                                            data2[key][category][chapterKey]
                                              .name
                                          }
                                        </span>
                                        <span
                                          className={` ml-auto h-5 w-5 shrink-0 ${openAccordian
                                            ? "rotate-[-180deg]"
                                            : "rotate-[0deg]"
                                            } fill-[#336dec] transition-transform duration-300 ease-in-out `}
                                        >
                                          <svg
                                            xmlns="http://www.w3.org/2000/svg"
                                            fill="none"
                                            viewBox="0 0 24 24"
                                            strokeWidth="1.5"
                                            stroke="currentColor"
                                            className="h-6 w-6"
                                          >
                                            <path
                                              strokeLinecap="round"
                                              strokeLinejoin="round"
                                              d="M19.5 8.25l-7.5 7.5-7.5-7.5"
                                            />
                                          </svg>
                                        </span>
                                      </button>
                                    </h2>
                                    <div
                                      className={`${openAccordian ? "" : "hidden"
                                        }`}
                                    >
                                      <div className="py-4 px-5">
                                        <div className="flex flex-col">
                                          <div className="overflow-x-auto sm:-mx-6 lg:-mx-8">
                                            <div className="inline-block min-w-full py-2 sm:px-6 lg:px-8">
                                              <div className="overflow-hidden">
                                                <table className="min-w-full text-left text-md font-normal">
                                                  <thead className="border-b font-medium">
                                                    <tr
                                                      className={`${categoryTextColor}`}
                                                    >
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        #
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        Topic Name
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        Video
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        PDF
                                                      </th>
                                                    </tr>
                                                  </thead>
                                                  <tbody>
                                                    {Object.keys(
                                                      data2[key][category][
                                                      chapterKey
                                                      ]
                                                    ).map((property) =>
                                                      property !== "name" ? (
                                                        <tr
                                                          key={property}
                                                          className="border-b text-black"
                                                        >
                                                          <td className="w-1/4 px-6 py-4 font-medium">
                                                            {property}
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            {
                                                              data2[key][
                                                                category
                                                              ][chapterKey][
                                                                property
                                                              ].topicName
                                                            }
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            <Link to={`/${course}/${className}/${subject}/chapters/${property}/${data2[key][
                                                              category
                                                            ][chapterKey][
                                                              property
                                                            ].topicName}/${data2[key][
                                                              category
                                                            ][chapterKey][
                                                              property
                                                            ].youtubelink}/${data2[key][
                                                                category
                                                              ][chapterKey][
                                                                property
                                                              ].pdflink
                                                              }`}>
                                                              Watch Video
                                                            </Link>
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            <a href={`https://drive.google.com/file/d/${data2[key][
                                                              category
                                                            ][chapterKey][
                                                              property
                                                            ].pdflink}`} download>Download PDF</a>
                                                          </td>
                                                        </tr>
                                                      ) : null
                                                    )}
                                                  </tbody>
                                                </table>
                                              </div>
                                            </div>
                                          </div>
                                        </div>
                                      </div>
                                    </div>
                                  </div>
                                )
                              )}
                            </div>
                          );
                        }
                      })}
                    </div>
                  );
                }
              })}
            </div>
          </div>
        </section>
      </div>


      <div className={`my-12  ${FCategory()[1] === "Inorganic" ? "block" : "hidden"
        }`}>
        <div className="w-full text-2xl py-4 text-center font-medium">
          {FCategory()[1]} Chemistry
        </div>
        <section
          className={`bg-white w-11/12 mx-auto`}
        >

          <div className="border border-neutral-200 bg-white">
            <div>
              {Object.keys(data2).map((key) => {
                if (key === FClass()) {
                  return (
                    <div key={key}>
                      {/* <div>Key: {key}</div> */}
                      {Object.keys(data2[key]).map((category) => {
                        if (category === FCategory()[1]) {
                          return (
                            <div key={category}>
                              {Object.keys(data2[key][category]).map(
                                (chapterKey) => (
                                  <div key={chapterKey}>
                                    {console.log(chapterKey)}
                                    <h2>
                                      <button
                                        className="group relative flex w-full items-center rounded-t-[15px] border-0 bg-white py-4 px-5 text-left text-base text-neutral-800 transition hover:z-[2] focus:z-[3] focus:outline-none [&:not [&:not([data-te-collapse-collapsed])]:[box-shadow:inset_0_-1px_0_rgba(229,231,235)]"
                                        type="button"
                                        onClick={() => {
                                          openAccordian
                                            ? setOpenAccordian(0)
                                            : setOpenAccordian(1);
                                        }}
                                      >
                                        <i
                                          className={`fa-solid fa-pen mr-4 ${categoryTextColor}`}
                                        ></i>
                                        <span className="font-medium">
                                          {chapterKey}:{" "}
                                          {data2[key][category][chapterKey].name}
                                        </span>
                                        <span
                                          className={` ml-auto h-5 w-5 shrink-0 ${openAccordian
                                            ? "rotate-[-180deg]"
                                            : "rotate-[0deg]"
                                            } fill-[#336dec] transition-transform duration-300 ease-in-out `}
                                        >
                                          <svg
                                            xmlns="http://www.w3.org/2000/svg"
                                            fill="none"
                                            viewBox="0 0 24 24"
                                            strokeWidth="1.5"
                                            stroke="currentColor"
                                            className="h-6 w-6"
                                          >
                                            <path
                                              strokeLinecap="round"
                                              strokeLinejoin="round"
                                              d="M19.5 8.25l-7.5 7.5-7.5-7.5"
                                            />
                                          </svg>
                                        </span>
                                      </button>
                                    </h2>
                                    <div
                                      className={`${openAccordian ? "" : "hidden"
                                        }`}
                                    >
                                      <div className="py-4 px-5">
                                        <div className="flex flex-col">
                                          <div className="overflow-x-auto sm:-mx-6 lg:-mx-8">
                                            <div className="inline-block min-w-full py-2 sm:px-6 lg:px-8">
                                              <div className="overflow-hidden">
                                                <table className="min-w-full text-left text-md font-light">
                                                  <thead className="border-b font-medium">
                                                    <tr
                                                      className={`${categoryTextColor}`}
                                                    >
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        #
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        Topic Name
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        Video
                                                      </th>
                                                      <th
                                                        scope="col"
                                                        className="px-6 py-4"
                                                      >
                                                        PDF
                                                      </th>
                                                    </tr>
                                                  </thead>
                                                  <tbody>
                                                    {Object.keys(
                                                      data2[key][category][
                                                      chapterKey
                                                      ]
                                                    ).map((property) =>
                                                      property !== "name" ? (
                                                        <tr
                                                          key={property}
                                                          className="border-b text-black"
                                                        >
                                                          <td className="w-1/4 px-6 py-4 font-medium">
                                                            {property}
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            {
                                                              data2[key][
                                                                category
                                                              ][chapterKey][
                                                                property
                                                              ].topicName
                                                            }
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            {
                                                              data2[key][
                                                                category
                                                              ][chapterKey][
                                                                property
                                                              ].youtubelink
                                                            }
                                                          </td>
                                                          <td className="w-1/4  px-6 py-4">
                                                            {
                                                              data2[key][
                                                                category
                                                              ][chapterKey][
                                                                property
                                                              ].pdflink
                                                            }
                                                          </td>
                                                        </tr>
                                                      ) : null
                                                    )}
                                                  </tbody>
                                                </table>
                                              </div>
                                            </div>
                                          </div>
                                        </div>
                                      </div>
                                    </div>
                                  </div>
                                )
                              )}
                            </div>
                          );
                        }
                      })}
                    </div>
                  );
                }
              })}
            </div>
          </div>
        </section>
      </div>
    </>
  );
}

export default Chapters;
