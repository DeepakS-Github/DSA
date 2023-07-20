import React, { useState } from "react";
import { useParams } from "react-router-dom";
import { Link } from "react-router-dom";


function CousesForOthersInBoards(props) {
  const { className } = useParams();


  const [showDropdown1, setShowDropdown1] = useState(0);

  const [showDropdown2, setShowDropdown2] = useState(0);

  const [showDropdown3, setShowDropdown3] = useState(0);

  const [showDropdown4, setShowDropdown4] = useState(0);

  

  return (
    <>
<section>
<div className={`container px-6 mx-auto  bg-gradient-to-r ${(className=="Class11"?"from-indigo-500 to-indigo-400":" from-rose-400 to-rose-300")}  subpixel-antialiased`}>
    
<section class="text-gray-800 background-radial-gradient ">
 

  <div class="px-6 py-12 md:px-12 text-center lg:text-left">
    <div class="container mx-auto">
      <div class="grid lg:grid-cols-2 gap-12 flex items-center">
        <div class="mt-16 lg:mt-0">
          <h1 class="text-4xl md:text-5xl xl:text-6xl font-bold tracking-tight mb-8 text-white"
            >
            {/* Class   <span>11<sup>th</sup></span> */}
            CBSE - {className}<sup>th</sup>
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

  <Link to={`/cbse/${className}/Chemistry/chapters`}>
      <section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/yS3XM9qx3hQ')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
            <i class={`fa-sharp fa-solid fa-flask  mr-2 ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>Chemistry
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
            "Exploring the building blocks of the universe with chemistry."
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-vial text-3xl  ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Elements</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
              <i class={`fa-solid fa-flask-vial text-3xl  ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Matter</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
              <i class={`fa-solid fa-atom text-3xl  ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Atom</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  ${(className=="Class11"?"bg-indigo-500 hover:bg-indigo-600":" bg-rose-500 hover:bg-rose-600")} mt-12 border-0 py-2 px-3 focus:outline-none  rounded text-md`}
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

  <Link to={`/cbse/${className}/Physics/chapters`}>
      <section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/gYrYa37fAKI')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
          <i class={`fa-solid fa-temperature-low text-3xl  ${(className=="Class11"?"text-indigo-500":" text-rose-500")} mr-2`}></i>Physics
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
          "Unlocking the secrets of the universe through the language of nature."
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-brands fa-space-awesome text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")} `}></i>
              </div>
              <div className="mt-1">Proofs</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid  fa-user-astronaut text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Patterns</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-fire-flame-simple text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Nature</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  mt-12   ${(className=="Class11"?"bg-indigo-500 hover:bg-indigo-600":" bg-rose-500 hover:bg-rose-600")} border-0 py-2 px-3 focus:outline-none  rounded text-md`}
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


      <Link to={`/cbse/${className}/Mathematics/chapters`}>
      <section class="text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/random?maths')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
            <i class={`fa-solid fa-not-equal ${(className=="Class11"?"text-indigo-500":" text-rose-500")} mr-2`}></i>Mathematics
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
          "Discover the beauty of logic and the power of numbers with mathematics."
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-calculator text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Precision</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid  fa-square-root-variable text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Computation</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-infinity text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Abstraction</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  mt-12   ${(className=="Class11"?"bg-indigo-500 hover:bg-indigo-600":" bg-rose-500 hover:bg-rose-600")} border-0 py-2 px-3 focus:outline-none rounded text-md`}
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
      </Link>

      <Link to={`/cbse/${className}/Biology/chapters`}>
      <section class="bg-white text-gray-600 py-8 flex justify-center items-center shadow-md   w-3/4 mx-auto my-20 body-font">
        <div className="w-2/5 flex h-[280px] justify-start py-8 mx-8 bg-[url('https://source.unsplash.com/random?biology')]"></div>
        <div className="w-3/5 h-full">
          <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
            <i class={`fa-solid fa-temperature-low ${(className=="Class11"?"text-indigo-500":" text-rose-500")} mr-2`}></i>Biology
          </h1>
          <h3 class="text-md mt-2 title-font text-gray-500">
          "Discovering the mysteries of life, one cell at a time."
          </h3>

          <div className="w-3/4 flex  mt-8">
            <div className="border-r-2 border-gray-400 h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-dna text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Research</div>
            </div>
            <div className=" h-full w-1/3 border-r-2 border-gray-400 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid  fa-tablets text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Observation</div>
            </div>
            <div className="h-full w-1/3 flex flex-col justify-center items-center">
              <div>
                <i class={`fa-solid fa-radiation text-3xl ${(className=="Class11"?"text-indigo-500":" text-rose-500")}`}></i>
              </div>
              <div className="mt-1">Methodology</div>
            </div>
          </div>
          <div className="relative w-full flex justify-end pr-16">
            <button
              class={`text-white relative  mt-12  ${(className=="Class11"?"bg-indigo-500 hover:bg-indigo-600":" bg-rose-500 hover:bg-rose-600")} border-0 py-2 px-3 focus:outline-none rounded text-md`}
              onMouseOver={(e)=>{
                e.preventDefault();
                setShowDropdown4(1);
              }}
              onMouseOut={(e)=>{
                e.preventDefault();
                setShowDropdown4(0);
              }}
            >
              <div>
                Enroll<i class="ml-2 text-sm fa-solid fa-angle-down"></i>
              </div>
              <ul
                class={`${
                  showDropdown4 ? "" : "hidden"
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
    </>
  );
}

export default CousesForOthersInBoards;
