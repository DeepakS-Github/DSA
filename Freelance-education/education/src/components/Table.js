import { React } from "react";
import { useState } from "react";
import { Link } from "react-router-dom";

function Table() {
  const [category, setCategory] = useState(1);

  return (
    <>
      <div className="w-full mb-8 mt-32 flex justify-center">
        <h1 class="md:text-3xl text-2xl font-medium title-font text-gray-900">
          Our Courses
        </h1>
      </div>
      <section className="w-3/4 mx-auto flex flex-row  my-12 mb-24 h-[450px]  shadow-md rounded-lg ">
        <div className="h-full w-1/4 bg-gray-100 ">
          <div className="h-3/5 w-full justify-evenly items-center flex flex-col">
            <button
              class="text-white bg-emerald-500 border-0 py-2 w-32 focus:outline-none hover:bg-emerald-600 rounded text-lg"
              onClick={(e) => {
                e.preventDefault();
                setCategory(1);
              }}
            >
              CBSE
            </button>
            <button
              class="text-white bg-emerald-500 border-0 py-2 w-32  focus:outline-none hover:bg-emerald-600 rounded text-lg"
              onClick={(e) => {
                e.preventDefault();
                setCategory(2);
              }}
            >
              JEE
            </button>
            <button
              class="text-white bg-emerald-500 border-0 w-32  py-2  focus:outline-none hover:bg-emerald-600 rounded text-lg"
              onClick={(e) => {
                e.preventDefault();
                setCategory(3);
              }}
            >
              NEET
            </button>
          </div>
        </div>

        <div className={`h-full w-3/4 ${category === 1 ? "block" : "hidden"} bg-white`}>
          <div className="w-full justify-evenly my-10 flex flex-row ">
            <Link to="/cbse/Class10">
              <div className="w-64 relative bg-gradient-to-r from-stone-300 to-neutral-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
                <div className="w-full pt-5 antialiased pl-5 text-neutral-900 font-semibold text-xl h-[20px]">
                  Class 10<sup>th</sup>
                  <div className="text-xs">CBSE</div>
                </div>
                <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-stone-600 flex justify-center items-center rounded-tl-full"></div>
                <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                  View Courses
                </span>
              </div>
            </Link>
            <Link to="/cbse/Class11">
              <div className="w-64 relative bg-gradient-to-r from-red-300 to-rose-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
                <div className="w-full pt-5 antialiased pl-5 text-rose-900 font-semibold text-xl h-[20px]">
                  Class 11<sup>th</sup>
                  <div className="text-xs">CBSE</div>
                </div>
                <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-red-600 flex justify-center items-center rounded-tl-full"></div>
                <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                  View Courses
                </span>
              </div>
            </Link>
            <Link to="/cbse/Class12">
              <div className="w-64 relative bg-gradient-to-r from-violet-300 to-purple-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
                <div className="w-full pt-5 antialiased pl-5 text-violet-900 font-semibold text-xl h-[20px]">
                  Class 12<sup>th</sup>
                  <div className="text-xs">CBSE</div>
                </div>
                <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-violet-600 flex justify-center items-center rounded-tl-full"></div>
                <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                  View Courses
                </span>
              </div>
            </Link>
          </div>
        </div>
        

        <div className={`h-full bg-white w-3/4 ${category === 2 ? "block" : "hidden"}`}>
          <div className="w-full justify-evenly my-10 flex flex-row ">
          <Link to="/jee/Class11">
            <div className="w-64 relative bg-gradient-to-r from-green-300 to-emerald-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
              <div className="w-full pt-5 antialiased pl-5 text-emerald-900 font-semibold text-xl h-[20px]">
                Class 11<sup>th</sup>
                <div className="text-xs">JEE</div>
              </div>
              <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-green-600 flex justify-center items-center rounded-tl-full"></div>
              <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                View Courses
              </span>
            </div>
            </Link>
            <Link to="/jee/Class12">
            <div className="w-64 relative bg-gradient-to-r from-blue-300 to-sky-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
              <div className="w-full pt-5 antialiased pl-5 text-sky-900 font-semibold text-xl h-[20px]">
                Class 12<sup>th</sup>
                <div className="text-xs">JEE</div>
              </div>
              <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-blue-600 flex justify-center items-center rounded-tl-full"></div>
              <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                View Courses
              </span>
            </div>
            </Link>
            <Link to="/jee/Advanced">
            <div className="w-64 relative bg-gradient-to-r from-pink-300 to-fuchsia-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
              <div className="w-full pt-5 antialiased pl-5 text-fuchsia-900 font-semibold text-xl h-[20px]">
                Advanced
                <div className="text-xs">JEE</div>
              </div>
              <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-pink-600 flex justify-center items-center rounded-tl-full"></div>
              <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                View Courses
              </span>
            </div>
            </Link>
          </div>
        </div>

        <div className={`h-full bg-white w-3/4 ${category === 3 ? "block" : "hidden"}`}>
          <div className="w-full justify-evenly my-10 flex flex-row ">
          <Link to="/neet/Class11">
            <div className="w-64 relative bg-gradient-to-r from-cyan-300 to-blue-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
              <div className="w-full pt-5 antialiased pl-5 text-blue-900 font-semibold text-xl h-[20px]">
                Class 11<sup>th</sup>
                <div className="text-xs">NEET</div>
              </div>
              <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-cyan-600 flex justify-center items-center rounded-tl-full"></div>
              <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                View Courses
              </span>
            </div>
            </Link>
            <Link to="/neet/Class12">
            <div className="w-64 relative bg-gradient-to-r from-amber-300 to-yellow-300 shadow-md overflow-hidden rounded-md h-[150px] cursor-pointer">
              
              <div className="w-full pt-5 antialiased pl-5 text-amber-900 font-semibold text-xl h-[20px]">
                Class 12<sup>th</sup>
              <div className="text-xs">NEET</div>
              </div>
              <div className="w-1/2 absolute -bottom-2 right-0 h-1/2 bg-amber-600 flex justify-center items-center rounded-tl-full"></div>
              <span className="text-slate-50 absolute bottom-0 right-0 pr-8 pb-3  text-lg font-semibold">
                View Courses
              </span>
            </div>
            </Link>
            <div className="w-64 relative overflow-hidden rounded-md h-[150px]"></div>
          </div>
        </div>
      </section>
    </>
  );
}

export default Table;
