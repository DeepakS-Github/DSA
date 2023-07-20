import React from 'react'
import AndroidApp from './AndroidApp'
import OurResults from './OurResults'
import OfflineCenter from './OfflineCenter'
import Table from './Table'
import Home1 from './Home1'
import Navbar from './Navbar'
import Testimonial from './Testimonial'
import About from './About'
function Home() {
  return (
    <>
      <Navbar />
      <Home1 />
      <About/>
      <Table />
      <OfflineCenter />
      <OurResults />
      <Testimonial />
      <AndroidApp />
    </>
  )
}

export default Home
