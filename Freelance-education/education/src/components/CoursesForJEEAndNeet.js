import React from 'react'
import { useParams } from "react-router-dom";
import { useState } from 'react';
import { Link } from 'react-router-dom';

function CoursesForJEEAndNeet() {


    const { className, course } = useParams();

  
    const [showDropdown1, setShowDropdown1] = useState(0);
  
    const [showDropdown2, setShowDropdown2] = useState(0);
  
    const [showDropdown3, setShowDropdown3] = useState(0);
  
  
    
    let checkCategory = () => {
        if(course==="neet"){
            if(className==="Class11"){
                return `from-slate-500 to-slate-400`
            }
            else if(className==="Class12"){
                return `from-emerald-500 to-emerald-400`
            }
        }
        else if(course==="jee"){
            if(className==="Class11"){
                return `from-teal-500 to-teal-400`
            }
            else if(className==="Class12"){
                return `from-lime-500 to-lime-400`
            }
            else if(className==="Advanced"){
                return `from-orange-500 to-orange-400`
            }
        }
    }


    let checkCategoryText = () => {
        if(course==="neet"){
            if(className==="Class11"){
                return `text-slate-500`
            }
            else if(className==="Class12"){
                return `text-emerald-500`
            }
        }
        else if(course==="jee"){
            if(className==="Class11"){
                return `text-teal-500`
            }
            else if(className==="Class12"){
                return `text-lime-500`
            }
            else if(className==="Advanced"){
                return `text-orange-500`
            }
        }
    }



    let checkCategoryButton = () => {
        if(course==="neet"){
            if(className==="Class11"){
                return `bg-slate-500 hover:bg-slate-600`
            }
            else if(className==="Class12"){
                return `bg-emerald-500 hover:bg-emerald-600`
            }
        }
        else if(course==="jee"){
            if(className==="Class11"){
                return `bg-teal-500 hover:bg-teal-600`
            }
            else if(className==="Class12"){
                return `bg-lime-500 hover:bg-lime-600`
            }
            else if(className==="Advanced"){
                return `bg-orange-500 hover:bg-orange-600`
            }
        }
    }


    





    const categoryColor = checkCategory();
    const categoryTextColor = checkCategoryText();
    const categoryButtonColor = checkCategoryButton();


  return (
    <>
    <section>
<div className={`container px-6 mx-auto  bg-gradient-to-r ${categoryColor} subpixel-antialiased`}>
    
<section class="text-gray-800 background-radial-gradient ">
 

  <div class="px-6 py-12 md:px-12 text-center lg:text-left">
    <div class="container mx-auto">
      <div class="grid lg:grid-cols-2 gap-12 flex items-center">
        <div class="mt-16 lg:mt-0">
          <h1 class="text-4xl md:text-5xl xl:text-6xl font-bold tracking-tight mb-8 text-white"
            >
            {/* Class   <span>11<sup>th</sup></span> */}
            <span className='uppercase'>{course}</span> - {className}<span className={`${className==="Advanced"?"hidden":""}`}><sup>th</sup></span>
          </h1>
          <p class="text-lg text-slate-100">
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Minima officia consequatur
            adipisci tenetur repudiandae rerum quos.
          </p>
        </div>
      </div>
    </div>
  </div>
</section>

</div>
</section>



<Link to={`/${course}/${className}/Physical+Inorganic-Chemistry/chapters`}>
<section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/random?science')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
            <i class={`fa-sharp fa-solid fa-flask  mr-2 ${categoryTextColor}`}></i>Physical+Inorganic Chemistry
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
            "Exploring the building blocks of the universe with chemistry."
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-vial text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Elements</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
              <i class={`fa-solid fa-flask-vial text-3xl  ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Matter</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
              <i class={`fa-solid fa-atom text-3xl  ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Atom</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  ${categoryButtonColor} mt-12 border-0 py-2 px-3 focus:outline-none  rounded text-md`}
              onMouseOver={(e)=>{
                e.preventDefault();
                setShowDropdown1(1);
              }}
              onMouseOut={(e)=>{
                e.preventDefault();
                setShowDropdown1(0);
              }}
            >
              <div>
                Enroll<i class="ml-2 text-sm fa-solid fa-angle-down"></i>
              </div>
              <ul
                class={`${
                  showDropdown1 ? "" : "hidden"
                }  absolute left-0 z-[1000] mt-2 float-left  min-w-max list-none overflow-hidden rounded-lg border-none bg-white bg-clip-padding text-left text-base shadow-lg dark:bg-neutral-700`}
              >
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Offline + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Home Tutor
                  </a>
                </li>
              </ul>
            </button>
          </div>
        </div>
      </section>
      </Link>


      <Link to={`/${course}/${className}/Organic-Chemistry/chapters`}>
      <section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/random?physics')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
          <i class={`fa-solid fa-temperature-low text-3xl  ${categoryTextColor} mr-2`}></i>Organic Chemistry
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
          "Discovering the building blocks of life and creating infinite possibilities"
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-capsules text-3xl ${categoryTextColor} `}></i>
              </div>
              <div className="mt-1">Molecules</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid  fa-circle-radiation text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Reactions</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-seedling text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Nature</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  mt-12   ${categoryButtonColor} border-0 py-2 px-3 focus:outline-none  rounded text-md`}
              onMouseOver={(e)=>{
                e.preventDefault();
                setShowDropdown2(1);
              }}
              onMouseOut={(e)=>{
                e.preventDefault();
                setShowDropdown2(0);
              }}
            >
              <div>
                Enroll<i class="ml-2 text-sm fa-solid fa-angle-down"></i>
              </div>
              <ul
                class={`${
                  showDropdown2 ? "" : "hidden"
                }  absolute left-0 z-[1000] mt-2 float-left  min-w-max list-none overflow-hidden rounded-lg border-none bg-white bg-clip-padding text-left text-base shadow-lg dark:bg-neutral-700`}
              >
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Offline + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Home Tutor
                  </a>
                </li>
              </ul>
            </button>
          </div>
        </div>
      </section>
      </Link>

      {/* <Link to={`/${course}/${className}/Mathematics/chapters`}>
      <section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/random?maths')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
            <i class={`fa-solid fa-microscope ${categoryTextColor} mr-2`}></i>All Chemistry
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
          "Unraveling the mysteries of matter and transforming our world"
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-eye-dropper text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Synthesis</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid  fa-prescription-bottle text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Computation</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-fire-flame-curved text-3xl ${categoryTextColor}`}></i>
              </div>
              <div className="mt-1">Abstraction</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  mt-12   ${categoryButtonColor} border-0 py-2 px-3 focus:outline-none rounded text-md`}
              onMouseOver={(e)=>{
                e.preventDefault();
                setShowDropdown3(1);
              }}
              onMouseOut={(e)=>{
                e.preventDefault();
                setShowDropdown3(0);
              }}
            >
              <div>
                Enroll<i class="ml-2 text-sm fa-solid fa-angle-down"></i>
              </div>
              <ul
                class={`${
                  showDropdown3 ? "" : "hidden"
                }  absolute left-0 z-[1000] mt-2 float-left  min-w-max list-none overflow-hidden rounded-lg border-none bg-white bg-clip-padding text-left text-base shadow-lg dark:bg-neutral-700`}
              >
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Online + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Offline + Instructor
                  </a>
                </li>
                <li>
                  <a
                    class="block w-full whitespace-nowrap bg-transparent py-2 px-4 text-sm font-normal text-neutral-700 hover:bg-neutral-100 active:text-neutral-800 active:no-underline disabled:pointer-events-none disabled:bg-transparent disabled:text-neutral-400 dark:text-neutral-200 dark:hover:bg-neutral-600"
                    href="#"
                  >
                    Home Tutor
                  </a>
                </li>
              </ul>
            </button>
          </div>
        </div>
      </section>
      </Link> */}


     

    </>
  )
}

export default CoursesForJEEAndNeet