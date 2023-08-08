import { useState } from 'react'
import axios, { AxiosError } from 'axios'
import './App.css'

// 型など
// ----------------------------------------------------------------
const API_BASE_URL = 'http://localhost:8000/api'

const ENDPOINTS = {
    TODO: `${API_BASE_URL}/todos`
}

type Todo = {
    id: number
    title: string
}

// ----------------------------------------------------------------

const App: React.FC = () => {
    const [getResponse, setGetResponse] = useState<Todo[]>([])
    const [postResponse, setPostResponse] = useState<string>('')

    const [formData, setFormData] = useState<{ title: string }>({
        title: ''
    })

    const getRequest = async () => {
        try {
            const response = await axios.get(ENDPOINTS.TODO)
            const data: Todo[] = await response.data
            setGetResponse(data)
        } catch (error) {
            console.log('get error')
        }
    }
    const postRequest = async () => {
        try {
            const response = await axios.post(ENDPOINTS.TODO, formData)
            setPostResponse(JSON.stringify(response.data))
        } catch (error) {
            const axiosError = error as AxiosError
            setPostResponse(JSON.stringify(axiosError.response?.data))
            console.log('post error')
        }
    }

    const handleInputChange = (event: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement>) => {
        const { name, value } = event.target
        setFormData({ ...formData, [name]: value })
    }

    return (
        <div>
            <h3>Todo GET</h3>
            <div style={{ margin: '20px', padding: '20px', backgroundColor: '#444444' }}>
                <ul>
                    {getResponse.map((todo, index) => (
                        <li key={index}>
                            id: {todo.id}, title: {todo.title}
                        </li>
                    ))}
                </ul>
            </div>

            <button onClick={getRequest}>GETリクエストを送信</button>

            <hr style={{ margin: '20px' }} />

            <h3>Todo POST</h3>

            <div>
                <label>
                    title:
                    <input
                        className="groove"
                        type="text"
                        name="title"
                        value={formData.title}
                        onChange={handleInputChange}
                        required
                    />
                </label>
            </div>

            <div style={{ margin: '20px', padding: '20px', backgroundColor: '#444444' }}>{postResponse}</div>
            <button onClick={postRequest}>POSTリクエストを送信</button>
        </div>
    )
}

export default App
