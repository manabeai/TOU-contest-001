
import './index.css'
import NameTag, { NameTagProps } from './name-tag';
type NameTagList = NameTagProps[];

const NameTags: NameTagList = new Array(20).fill(  {
  name: '真鍋愛',
  atcoder: 'manabeai',
  img: 'manabeai.jpg',
})

function App() {
  return (
    <>
      <h1 className="print-area">
        {NameTags.map((tag, index) => (
          <NameTag key={index} {...tag} />
        ))}
      </h1>
    </>
  );
}

export default App
