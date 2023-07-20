// import Navbar from './compt from 'react'
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'
import Home from './components/Home'
import CoursesFor10th from './components/CoursesFor10th'
import CousesForOthersInBoards from './components/CousesForOthersInBoards'
import Chapters from './components/Chapters'
import CoursesForJEEAndNeet from './components/CoursesForJEEAndNeet'
import Yt from './components/Yt'
import { Pdf } from './components/Pdf'
import YoutubeAndFile from './components/YoutubeAndFile'
import Testimonial from './components/Testimonial'
import Footer from './components/Footer'


function App() {
  return (
    <>
      {/* <Navbar /> */}
      <Router>
        <Routes>
          <Route exact path="/" element={<Home />} />
          <Route exact path="/cbse/class10" element={<CoursesFor10th />} />
          <Route
            exact
            path="/cbse/:className"
            element={<CousesForOthersInBoards />}
          />
          <Route
            exact
            path="/:course/:className"
            element={<CoursesForJEEAndNeet />}
          />
          <Route exact path="/:course/:className/:subject/chapters" element={<Chapters />} />
          <Route exact path="/:course/:className/:subject/chapters/:topic/:name/:video/:pdf" element={<YoutubeAndFile/>} />
          {/* <Route exact path="/youtube" element={<YoutubeAndFile />} />
          <Route exact path="/pdf" element={<Testimonial />} /> */}
        </Routes>
      </Router>
      <Footer/>
    </>
  )
}

export default App
