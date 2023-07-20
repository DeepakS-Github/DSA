import React from "react";

function AndroidApp() {
  return (
    <>

    <div className="flex flex-col justify-between max-w-xl px-4 mx-auto lg:pt-16 lg:flex-row md:px-8 lg:max-w-screen-xl">
      <div className="lg:mb-0 lg:pt-32 lg:max-w-lg lg:pr-5">
        <div className="max-w-xl mb-6">
          <div>
            <p className="inline-block px-3 py-px mb-4 text-xs font-semibold tracking-wider text-teal-900 uppercase rounded-full bg-teal-accent-400">
              theallclasses
            </p>
          </div>
          <h2 className="max-w-lg mb-6 font-sans text-3xl font-bold tracking-tight text-gray-900 sm:text-4xl sm:leading-none">
          Get the Best Experience with Our App
          </h2>
          <p className="text-base text-gray-700 md:text-lg">
          Our innovative education technology app is designed to help you
            achieve your academic goals with ease. With its intuitive interface,
            engaging content, and personalized learning tools, our app will make
            studying a breeze.
          </p>
        </div>
        <div className="flex items-center">
        <button class="bg-white inline-flex py-3 px-5 rounded-lg items-center hover:bg-gray-200 focus:outline-none shadow">
            <svg
              xmlns="http://www.w3.org/2000/svg"
              fill="currentColor"
              class="w-6 h-6"
              viewBox="0 0 512 512"
            >
              <path d="M99.617 8.057a50.191 50.191 0 00-38.815-6.713l230.932 230.933 74.846-74.846L99.617 8.057zM32.139 20.116c-6.441 8.563-10.148 19.077-10.148 30.199v411.358c0 11.123 3.708 21.636 10.148 30.199l235.877-235.877L32.139 20.116zM464.261 212.087l-67.266-37.637-81.544 81.544 81.548 81.548 67.273-37.64c16.117-9.03 25.738-25.442 25.738-43.908s-9.621-34.877-25.749-43.907zM291.733 279.711L60.815 510.629c3.786.891 7.639 1.371 11.492 1.371a50.275 50.275 0 0027.31-8.07l266.965-149.372-74.849-74.847z"></path>
            </svg>
            <span class="ml-4 flex items-start flex-col leading-none">
              <span class="text-xs text-gray-600 mb-1">GET IT ON</span>
              <span class="title-font font-medium">Google Play</span>
            </span>
          </button>
        </div>
      </div>
      <div>
        <img
          src="https://kitwind.io/assets/kometa/two-thirds-phone.png"
          className="object-cover object-top w-full h-64 mx-auto lg:h-auto xl:mr-24 md:max-w-sm"
          alt=""
        />
      </div>
    </div>


    </>
  );
}

export default AndroidApp;
