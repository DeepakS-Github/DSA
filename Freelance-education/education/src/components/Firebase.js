import firebase from "firebase/compat/app";
import "firebase/compat/firestore";

// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyCdZTq1_5XrObz8dAcOMhnb00aB04keelw",
  authDomain: "theallclasses.firebaseapp.com",
  projectId: "theallclasses",
  storageBucket: "theallclasses.appspot.com",
  messagingSenderId: "691917746901",
  appId: "1:691917746901:web:b68f21471a2bea9ee7e85c",
  measurementId: "G-RFNJJ4BP7Q"
};

firebase.initializeApp(firebaseConfig);

export default firebase;

