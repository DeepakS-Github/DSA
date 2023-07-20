import React from 'react'
import background from './OfflineCenter.jpg'

function OfflineCenter() {
    

  return (
    <section class="text-gray-600 h-[350px] flex justify-center items-center shadow-md   w-3/4 mx-auto my-32 body-font bg-white rounded-lg">
       
        <div className='w-2/5 flex mr-4 justify-start px-8 py-8 h-full'>
            <img className="w-full r-8 mx-2 bg-slate-700 rounded-lg" src={`${background}`} alt=''></img>
        </div>
        <div className='w-3/5 h-full'>
            <h1 class="md:text-3xl mt-9 text-2xl font-medium title-font text-gray-900">
                Reach Our Offline Center
            </h1>
            <h3 class="md:text-lg text-md mt-2 title-font text-gray-500">
                Available In Noida, New Delhi
            </h3>
            <ul className='list-inside text-lg list-none font-normal leading-8 my-8 text-emerald-600'>
                <li><i class="fa-regular fa-circle-check mx-2 text-emerald-600 "></i>Personalized attention</li>
                <li><i class="fa-regular fa-circle-check mx-2 text-emerald-600"></i>Interactive learning environment</li>
                <li><i class="fa-regular fa-circle-check mx-2 text-emerald-600"></i>Effective assessment and evaluation</li>
            </ul>
            <button class="text-white bg-emerald-500 border-0 py-2 px-6 focus:outline-none hover:bg-emerald-600 rounded text-lg">Reach Us</button>

            
        </div>
       
    </section>
  );
}


export default OfflineCenter