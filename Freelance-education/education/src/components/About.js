import React from 'react'

function About() {
  return (
   <>
   <section class="bg-white py-16 dark:bg-gray-900">
    <div class="gap-16 items-center py-8 px-4 mx-auto max-w-screen-xl lg:grid lg:grid-cols-2 lg:py-16 lg:px-6">
        <div class="text-gray-500 sm:text-lg dark:text-gray-400">
            <h2 class="mb-4 md:text-4xl text-3xl font-medium title-font text-gray-900">ABOUT</h2>
            <p class="mb-4 text-lg text-gray-700">Lorem ipsum dolor sit amet consectetur adipisicing elit. Qui ad nemo numquam similique? Vero iusto in repellat magni voluptatum cupiditate ea autem aut quaerat! Exercitationem culpa tempore accusantium magni assumenda recusandae. Doloribus dolore harum libero sunt officiis aliquam reiciendis corporis ad<p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Aut corrupti suscipit reiciendis ratione asperiores error, accusantium dolorum facere quisquam doloremque voluptatem sed magnam, atque sit, dicta hic sunt? Optio eveniet dolore distinctio voluptas ipsam?</p></p>
        </div>
        <div class="grid grid-cols-2 gap-4 mt-8">
            <img class="w-full rounded-lg" src="https://source.unsplash.com/0AZpF_IaH6g" alt="office content 1"/>
            <img class="mt-4 w-full lg:mt-10 rounded-lg" src="https://source.unsplash.com/DegTqYxUDFo" alt="office content 2"/>
        </div>
    </div>
</section>
   </>
  )
}

export default About